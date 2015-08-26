# larry-screweater
This is an example of how to program a game using [SFML](http://www.sfml-dev.org/). The game is about a robot who likes to eat screws.

The code is intendedly left rather simple. Usually I would encapsulate all entities in distinct classes, but this time I only decoupled input processing, game logic and rendering - to keep things simple.

Feel free to download, compile and play the game. You may also use, modify and redistribute the code under the terms of the zlib license.

# Building
You can compile the code using cmake:

    git clone https://github.com/fabian-rump/larry-screweater.git
    cd larry-screweater
    cmake .
    make
    
# License
zlib License. See `LICENSE` file for details.

# Used assets
* Robot and Screw image from [openclipart](https://openclipart.org) (Public domain)
* Background image from [bgrepeat](http://bgrepeat.com/bg_128-161) (free for personal and commercial works)
* [Roboto font](http://developer.android.com/design/style/typography.html) from Android (Apache license)
