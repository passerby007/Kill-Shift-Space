# Kill-Shift-Space

> Millions of wasted keystrokes, zero response from Microsoft, FOR A DECADE.

## The Problem

If you've ever typed in Chinese on Windows, you know the pain. You're happily typing away, and then — BAM — you accidentally hit `Shift+Space`, and suddenly everything turns into ｆｕｌｌ－ｗｉｄｔｈ　ｃｈａｒａｃｔｅｒｓ. Your code breaks. Your messages look drunk. Your soul leaves your body.

This has been a well-known, widely-reported, universally-hated annoyance for **over a decade**. Countless users have begged Microsoft to add a simple toggle to disable it. Microsoft's response? *Silence. Absolute silence.*

### "But can't you just disable it in Microsoft Pinyin settings?"

No. Well, *technically* yes — there is a toggle in Microsoft Pinyin's settings to disable the `Shift+Space` full-width shortcut. It's right there, looking all official and functional. **Except it doesn't work.** It's bugged. You flip the switch, and `Shift+Space` keeps toggling full-width mode like nothing happened. This bug has been reported by users over and over again. Microsoft's response? Same as always — absolutely nothing.

So not only did they refuse to add a system-level option to disable it, the one option they *did* provide **is broken**. You can't make this stuff up.

So here we are. Fixing it ourselves. With 50 lines of C++.

## What It Does

`kill-shift-space.exe` runs silently in the background and intercepts the `Shift+Space` hotkey globally. When you press `Shift+Space`, instead of toggling full-width/half-width mode, it simply types a regular space. That's it. That's the whole program.

No more ｆｕｌｌ－ｗｉｄｔｈ　ｎｉｇｈｔｍａｒｅｓ.

## Usage

### Start the killer

Double-click `kill-shift-space.exe`. It runs in the background with no window. Done.

### Retreat the killer

Want `Shift+Space` back for some reason? Run `retreat-killer.exe`. It finds and terminates the `kill-shift-space` process.

```
retreat-killer.exe
> Killed kill-shift-space.exe (PID: 12345)
```

### Build from source

Make sure you have CMake and MSVC installed, then:

```bat
cmake -B .build -S .
cmake --build .build --config Release
```

Or just double-click `build.bat`.

Executables will appear in the `.output` folder.

## Pro Tips

- Add `kill-shift-space.exe` to your Windows startup folder so it runs automatically on boot.  
  Press `Win+R`, type `shell:startup`, and drop a shortcut there.
- `retreat-killer.exe` may need admin privileges if `kill-shift-space.exe` was started as admin.

## Dear Microsoft

We shouldn't need this. A single checkbox in Settings would have saved millions of people millions of hours. But here we are, in the year 2026, writing our own hotkey interceptors because a trillion-dollar company can't be bothered to add an option to disable a keybind that **nobody wants**.

You're welcome.

## License

MIT — because unlike some companies, we believe in giving people what they ask for.
