Run command with CJK-friendly wcwidth(3) to fix ambiguous width chars
======================================================================

  * Copyright (c) 2013 SATOH Fumiyasu @ OSS Technology Corp., Japan
  * License: BSD-like (2-clause, see wcwidth.c)
  * URL: <https://GitHub.com/fumiyas/wcwidth-cjk>
  * Twitter: <https://twitter.com/satoh_fumiyasu>

What's this?
---------------------------------------------------------------------

This is a `$LD_PRELOAD`-able library and a wrapper script to
run a command with CJK-friendly `wcwidth`(3) implementation for
fixing "East Asian Ambiguous Width chars" problem.

日本語 (In Japanese): 「East Asian Ambiguous Width chars 問題」を
解決するための `$LD_PRELOAD` 可能な共有ライブラリーとラッパー
スクリプトです。「α」などの「East Asian Ambiguous Width chars」の
表示や編集で問題が発生するコマンドをこの実装下で起動すると、
システム標準の `wcwidth`(3) が置き換えられ、問題を解消できます。

How to build
---------------------------------------------------------------------

    $ make
    ...
    $ sudo make install
    ...

If you are on Mac OS X, apply the bundled patch before `make`:

    $ patch -p1 <wcwidth-cjk-for-macosx.patch

Usage
---------------------------------------------------------------------

Run a command with `$LD_PRELOAD`-able library:

    $ export LD_PRELOAD=/usr/local/lib/wcwidth-cjk.so
    $ zsh
    ...

or:

    $ eval `/usr/local/bin/wcwidth-cjk --sh-init`
    $ zsh
    ...

Run a command via wrapper script:

    $ /usr/local/bin/wcwidth-cjk zsh
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

