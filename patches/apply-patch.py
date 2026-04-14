import argparse
import subprocess
import sys
from pathlib import Path

# ===================== CONFIGURATION =====================
# Ordered patch groups:
# Each inner list is applied in order.
# Groups themselves are applied in order.
RIOT_ORDER = [
    [
        "CVE-2021-31660.diff",
        "CVE-2021-31661.diff",
    ],
    [
        "CVE-2023-24822.diff",
        "CVE-2023-24823.diff",
        "CVE-2023-33973.diff",
        "CVE-2023-24820.diff",
    ],
]

CONTIKI_ORDER = [
    [ "CVE-2023-48229.diff", ],
    [ "CVE-2022-36054.diff", 
     "CVE-2022-36052.diff", 
     "CVE-2021-21410.diff", 
     "CVE-2023-37281.diff", ],
    [ "CVE-2023-37459.diff", ],
    [ "CVE-2023-31129.diff",
      "CVE-2022-35926.diff", ],
    [ "CVE-2022-36053.diff", ],
    [ "CVE-2023-28116.diff",
     "CVE-2023-23609.diff", 
     "CVE-2022-41972.diff",  
     "CVE-2022-41873.diff", ],
    [ "CVE-2021-21282.diff", ],
    [ "CVE-2021-32771.diff", 
     "CVE-2023-34101.diff", 
     "CVE-2022-35927.diff", ],
    [ "CVE-2023-50926.diff", 
     "CVE-2023-50927.diff", ],
    [ "CVE-2023-30546.diff", ],
]

ZEPHYR_ORDER = [
    ["CVE-2021-3454.diff",
     "CVE-2021-3435.diff"],
     ["CVE-2022-1041.diff",
      "CVE-2022-1042.diff"]
]

ORDERED_PATCH_GROUPS = ZEPHYR_ORDER 

# ========================================================


def run_patch(patch_path: Path) -> bool:
    """
    Apply a patch using git apply and print stdout/stderr.
    Returns True on success, False on failure.
    """
    print(f"\n=== Applying patch: {patch_path.name} ===")

    proc = subprocess.run(
        ["git", "apply", str(patch_path)],
        capture_output=True,
        text=True,
    )

    if proc.stdout:
        print("stdout:")
        print(proc.stdout)

    if proc.stderr:
        print("stderr:")
        print(proc.stderr)

    if proc.returncode == 0:
        print(f"[SUCCESS] {patch_path.name}")
        return True
    else:
        print(f"[FAILURE] {patch_path.name}")
        return False


def parse_args():
    parser = argparse.ArgumentParser(description="Process/apply patches from a directory.")
    parser.add_argument(
        "patch_dir",
        type=Path,
        help="Directory containing .diff patch files",
    )
    return parser.parse_args()

def main():

    args = parse_args()

    if not args.patch_dir.is_dir():
        print(f"Patch directory not found: {args.patch_dir}")
        sys.exit(1)

    all_patches = {p.name: p for p in args.patch_dir.glob("*.diff")}

    applied = set()

    # 1. Apply ordered patch groups
    for group in ORDERED_PATCH_GROUPS:
        for patch_name in group:
            patch_path = all_patches.get(patch_name)

            if not patch_path:
                print(f"[WARNING] Patch not found: {patch_name}")
                continue

            success = run_patch(patch_path)
            applied.add(patch_name)

            if not success:
                print("Stopping due to failure in ordered patches.")
                sys.exit(1)

    # 2. Apply remaining patches in any order
    remaining_patches = [
        p for name, p in all_patches.items() if name not in applied
    ]

    for patch_path in remaining_patches:
        run_patch(patch_path)


if __name__ == "__main__":
    main()
