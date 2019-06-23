Run command with CJK-friendly wcwidth(3) to fix ambiguous width chars
======================================================================

  * Copyright (c) 2013-2019 SATOH Fumiyasu @ OSS Technology Corp., Japan
  * License: BSD-like (2-clause, see wcwidth.c)
  * URL: <https://GitHub.com/fumiyas/wcwidth-cjk>
  * Twitter: <https://twitter.com/satoh_fumiyasu>

What's this?
---------------------------------------------------------------------

This is a `$LD_PRELOAD`-able library and a wrapper script to
run a command with CJK-friendly `wcwidth`(3) implementation for
fixing "East Asian Ambiguous Width Characters" problem.

日本語 (In Japanese): 「East Asian Ambiguous Width chars 問題」を
解決するための `$LD_PRELOAD` 可能な共有ライブラリーとラッパー
スクリプトです。「α」などの「East Asian Ambiguous Width chars」の
表示や編集で問題が発生するコマンドをこの実装下で起動すると、
システム標準の `wcwidth`(3) が置き換えられ、問題を解消できます。

How to build
---------------------------------------------------------------------

Required packages: autoconf, automake, libtool, make, cc (gcc or misc)

    $ sh autogen.sh
    $ ./configure --prefix=/usr/local
    $ make
    $ sudo make install

Usage
---------------------------------------------------------------------

Run a command with `$LD_PRELOAD`-able library:

    $ export LD_PRELOAD=/usr/local/lib/wcwidth-cjk.so
    $ exec zsh -l
    ...

or:

    $ eval `/usr/local/bin/wcwidth-cjk --sh-init`
    $ exec zsh -l
    ...

Run a command via wrapper script:

    $ /usr/local/bin/wcwidth Ab漢α¥
    1 00 00 00 41   A
    1 00 00 00 62   b
    2 00 00 6F 22   漢
    1 00 00 03 B1   α
    1 00 00 00 A5   ¥
    $ /usr/local/bin/wcwidth-cjk /usr/local/bin/wcwidth Ab漢α¥
    1 00 00 00 41   A
    1 00 00 00 62   b
    2 00 00 6F 22   漢
    2 00 00 03 B1   α
    1 00 00 00 A5   ¥
    $ exec /usr/local/bin/wcwidth-cjk zsh -l
    ...

References
---------------------------------------------------------------------

  * East Asian Ambiguous Width chars problem
    + http://sourceware.org/bugzilla/show_bug.cgi?id=4335
    + http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=471021
    + http://d.hatena.ne.jp/vmi/20090523/p1
    + http://d.hatena.ne.jp/vmi/20090524/p1
    + http://d.hatena.ne.jp/vmi/20090526/p1
    + http://d.hatena.ne.jp/vmi/20090604/p1
    + http://ta.ps.st/d/1331733974.html
    + http://vdr.jp/d/20070326.html
  * CJK-friendly `wcwidth`(3) (`wcwidth_cjk()` in `wcwidth.c`): 
    + http://www.cl.cam.ac.uk/~mgk25/ucs/wcwidth.c
    + ftp://ftp.mutt.org/mutt/devel/
    + http://www.emaillab.org/mutt/download1521.html
    + https://twitter.com/ttkzw/status/341958235814768640
    + https://twitter.com/ttkzw/status/341954474333581313
    + https://twitter.com/ttkzw/status/341960339300159488
  * hamano/locale-eaw: East Asian Ambiguous Width問題の修正ロケール
    * https://github.com/hamano/locale-eaw
  * Emoji - Wikipedia, the free encyclopedia
    * https://en.wikipedia.org/wiki/Emoji
  * uwabami/locale-eaw-emoji: UAX#11 Ambiguous と UTR #51 Emoiji を全角とする修正 locale
    * https://github.com/uwabami/locale-eaw-emoji

