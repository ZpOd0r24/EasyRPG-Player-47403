# TsukiYumeRPG/EasyRPG-Player

Some new features of EasyRPG Player, primarily for multiplayer.

The first commit of EPMP is [44347b6](https://github.com/TsukiYumeRPG/EasyRPG-Player/commit/44347b6) (Initial commit. Add multiplayer changes), based on [ynoclient:cd7b46d](https://github.com/ynoproject/ynoengine/tree/cd7b46d) 2023-05-31.

Not sure how to use it? You can refer to the [tutorial].

If you are interested in this project, you can clone the repository to your local system to browse the code. If you don't know how to use Git, please refer to: [Git Manual](https://git-scm.com/book/en/v2).

Remember to switch to the `dev` branch, as many updates will be submitted there first.


## Requirements

- [libuv] for networking
- [libsodium] for encryption


## Credits

### \[Fork-02 from twig33-ynoclient\] [ynop-ynoengine](https://github.com/ynoproject/ynoengine) (2024-03)

- Flashfyre (sam): Synchronization, Web, ChatName (NameTag), ...
- maru (pancakes): Merge upstream, Handle merge conflicts, Web, ChatName, ...
- aleck099: New YNO protocol, Connection and data, Async download, ...

### \[Fork-01 from twig33-ynoclient\] [Char0x61-ynoclient](https://github.com/CataractJustice/ynoclient) (2022-06)

- Char0x61 (CataractJustice): Split & Improve, Char0x61's nametags, Settings Scene, ...
- xiaodao (苏半岛): In-game chat translation, Font bug fix, ...
- Led (Biel Borel): In-game chat original implementation, ...

### \[Original\] [twig33-ynoclient](https://github.com/twig33/ynoclient) (2021-11)

- twig33: Original concept and implementation

### Additional thanks

- [Jixun](https://github.com/jixunmoe) for helping in the C++ problems
- [Ratizux](https://github.com/Ratizux) for the podman suggestions
- [Proselyte093](https://github.com/Proselyte093) for giving the project a chance to compile on the macOS ARM
- AI for various types of knowledge
- With help from various participants

### Greetings to

[EasyRPG](https://github.com/EasyRPG), [twig33](https://github.com/twig33), [Flashfyre](https://github.com/Flashfyre),
[aleck099](https://github.com/aleck099), [Ledgamedev](https://github.com/Ledgamedev),
[Char0x61](https://github.com/CataractJustice), [maru](https://github.com/patapancakes),
[JeDaYoshi](https://github.com/JeDaYoshi), [kekami](https://kekami.dev),
[苏半岛](https://github.com/lychees), azarashi, Altiami


## License

For EPMP licensing, see [epmp-license.txt]

### 3rd party software

EPMP makes use of the following 3rd party software:

* [minetest util] Minetest C/C++ code - Copyright (C) 2010 celeron55,
  Perttu Ahola \<celeron55@gmail.com\>, provided under the LGPLv2.1+
* [socks5.h] Modern C++ SOCKS5 Client Handler - by harsath, provided under MIT


[tutorial]: /docs/epmp/tutorial.md
[liblcf]: https://github.com/EasyRPG/liblcf
[minetest util]: https://github.com/minetest/minetest
[socks5.h]: https://github.com/harsath/SOCKS5-Proxy-Handler
[libuv]: https://github.com/libuv/libuv
[libsodium]: https://github.com/jedisct1/libsodium
[epmp-license.txt]: /docs/epmp/license.txt
