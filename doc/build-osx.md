macOS Build Instructions and Notes
====================================
The commands in this guide should be executed in a Terminal application.
The built-in one is located in `/Applications/Utilities/Terminal.app`.

Preparation
-----------
Install the macOS command line tools:

`xcode-select --install`

When the popup appears, click `Install`.

// lines 19 to 31 commented out for reference
// "Homebrew" are not official build tools for OSX
// see "OSX executable? #39" on issues tab for work in progress notes
// OSX, build from source instructions, currently unavalible

// Then install [Homebrew](https://brew.sh).

// Base build dependencies
// -----------------------

// ```bash
// brew install automake libtool pkg-config libnatpmp
// ```

// If you want to build the disk image with `make deploy` (.dmg / optional), you need RSVG:
// ```bash
// brew install librsvg
// ```

Building
--------

It's possible that your `PATH` environment variable contains some problematic strings, run
```bash
export PATH=$(echo "$PATH" | sed -e '/\\/!s/ /\\ /g') # fix whitespaces
```

Next, follow the instructions in [build-generic](build-generic.md)

Disable-wallet mode
--------------------
When the intention is to run only a P2P node without a wallet, Bitcoin Core may be compiled in
disable-wallet mode with:

    ./configure --disable-wallet

In this case there is no dependency on Berkeley DB 4.8.

Mining is also possible in disable-wallet mode using the `getblocktemplate` RPC call.

Running
-------

SCC Core is now available at `./src/sccd`

Before running, you may create an empty configuration file:

    mkdir -p "/Users/${USER}/Library/Application Support/StakeCubeCoin"

    touch "/Users/${USER}/Library/Application Support/StakeCubeCoin/stakecubecoin.conf"

    chmod 600 "/Users/${USER}/Library/Application Support/StakeCubeCoin/stakecubecoin.conf"

The first time you run sccd, it will start downloading the blockchain. This process could take many hours, or even days on slower than average systems.

You can monitor the download process by looking at the debug.log file:

    tail -f $HOME/Library/Application\ Support/StakeCubeCoin/debug.log

Other commands:
-------

    ./src/sccd -daemon # Starts the scc daemon.
    ./src/scc-cli --help # Outputs a list of command-line options.
    ./src/scc-cli help # Outputs a list of RPC commands when the daemon is running.
