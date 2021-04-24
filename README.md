# dwm - dynamic window manager

dwm is another minimalist piece of software from suckless.org - specifically, a window manager written in less than 2000 lines of C.

## Patches

- [shiftview](https://lists.suckless.org/dev/1104/7590.html)
- [systray](https://dwm.suckless.org/patches/systray/)
- [staticstatus](https://dwm.suckless.org/patches/staticstatus/)
- [cycle layout](https://dwm.suckless.org/patches/cyclelayouts/)
- [always center](https://dwm.suckless.org/patches/alwayscenter/)
- [rotate stack](https://dwm.suckless.org/patches/rotatestack/)
- [notify thing](https://dwm.suckless.org/patches/focusonnetactive/)
- [warp](https://dwm.suckless.org/patches/warp/)
- [no border](https://dwm.suckless.org/patches/noborder/)

- [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/)
- [barpadding](https://dwm.suckless.org/patches/barpadding/)
- [statuspadding](https://dwm.suckless.org/patches/statuspadding/)
- [barheight](https://dwm.suckless.org/patches/bar_height/)
- [cfacts](https://dwm.suckless.org/patches/cfacts/)
- [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/)
I had to use a verison of vanitygaps that combined with cfacts. was a pain to patch manually

## Patches to look at in the future:

- [notitle](https://dwm.suckless.org/patches/notitle/)

## Notes

Tip: if you are getting massive error messages, output the errors to a file using
make 2> errors.txt
Then read the first line - usually that's where you'll be missing a semicolon or something like that.


Inspiration from @ChristianChiarulli!

Starting 4/21/2021...
