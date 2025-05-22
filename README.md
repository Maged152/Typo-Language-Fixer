# TypeLangFixer

TypeLangFixer is a simple utility (for Windows) that helps you quickly fix text in your clipboard when you accidentally type in the wrong keyboard language (`English`/`Arabic`). If you meant to type in Arabic but your keyboard was set to English (or vice versa), this tool will convert the clipboard text using a keyboard-based lookup table and update your clipboard with the corrected text.

---

## Features

- **Clipboard Integration:** Reads the current clipboard text (what you copied with `Ctrl+C`).
- **Keyboard Layout Correction:** Converts text between English and Arabic based on the the copied text.
- **Quick Fix:** After copying the wrong text, run the app and your clipboard is instantly fixed.
- **Easy Shortcut Integration:** Assign a global shortcut (e.g., `Ctrl+Win+Z`) to run the app for instant correction.

---

## How It Works

1. **Copy Text:** Select and copy the text you typed in the wrong language using `Ctrl+C`.
2. **Run TypeLangFixer:** Execute the app (either by double-clicking or using a shortcut).
3. **Clipboard Fixed:** The app detects the language, converts the text using the lookup table, and updates your clipboard.
4. **Paste:** Use `Ctrl+V` to paste the corrected text wherever you need.

**Example:**  
You meant to type Arabic, but your keyboard was set to English and you typed:  
`sghl`  
Copy it, run TypeLangFixer, and your clipboard will now contain:  
`سلام`

---

## Installation

### 1. Clone the Repository
```
git clone https://github.com/Maged152/Typo-Language-Fixer.git
```
### 2.  Build the Project
```
cmake -S <source_dir> -B <build_dir>
cmake --build <build_dir>
```
### 3.  Install the App
```
cmake --install <build_dir> --prefix <install_dir>
```
### 4. (Optional) Assign a Shortcut 
For convenience, you can assign a global shortcut to run `<install_dir>/bin/TypeLangFixer_exec.exe`


## Supported Platforms

- **Windows:** Uses the native clipboard API.

---

## Notes

- This tool does **not** translate between English and Arabic; it remaps the characters based on the keyboard layout.
- Works best for fixing text typed with the wrong keyboard language setting.
- For best experience, assign a global shortcut to the executable.

---

## Example

| Mistyped                    | Intended                   |
|-----------------------------|----------------------------|
| hgsghl ugd;l                | السلام عليكم               |
| اثممخ صخقمي                | hello world                |

---

## Contributing

Pull requests and suggestions are welcome!

---

## License

MIT License
```
This is ready to use as your README.md.
