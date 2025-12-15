import subprocess
import sys
from pathlib import Path

# ===================== CONFIGURATION =====================

# Directory containing .diff files
PATCH_DIR = Path("patches")  # <-- change if needed

# Ordered patch groups:
# Each inner list is applied in order.
# Groups themselves are applied in order.
ORDERED_PATCH_GROUPS = [
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


def main():
    if not PATCH_DIR.is_dir():
        print(f"Patch directory not found: {PATCH_DIR}")
        sys.exit(1)

    all_patches = {p.name: p for p in PATCH_DIR.glob("*.diff")}

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
