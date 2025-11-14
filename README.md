# Spotify Controller

## Description

Spotify Controller is a command-line tool to control Spotify playback using DBus commands. It allows you to play, pause, skip tracks, and display the current track information directly from the terminal.

## Features

- Play the current track
- Pause the current track
- Play the next track
- Play the previous track
- Show the current track information (song, artist, length)

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/3d3n-pyc/spotify-controller.git
    cd spotify-controller
    ```

2. Build the project:
    ```sh
    make
    ```

## Usage

Run the spotify command with the desired options and subcommands:

```sh
./spotify [OPTIONS] [SUBCOMMANDS]
```

### Options

- `-h, --help`: Show the help message and exit

### Subcommands

- `play`: Play the current track
- `pause`: Pause the current track
- `next`: Play the next track
- `prev`: Play the previous track
- `current`: Show the current track information

## Examples

- Play the current track:
    ```sh
    ./spotify play
    ```
- Pause the current track:
    ```sh
    ./spotify pause
    ```
- Play the next track:
    ```sh
    ./spotify next
    ```
- Play the previous track:
    ```sh
    ./spotify prev
    ```
- Show the current track information:
    ```sh
    ./spotify current
    ```

## Development

### Required

- `gcc` (GNU Compiler Collection)
- `make` (GNU Make)
- `readline` (GNU Readline Library)

### Build

To build the project, run the following command:

```sh
make
```

### Clean

To clean the project, run the following command:

```sh
make clean
```

### Debug

To build the project with debugging information, run the following command:

```sh
make debug
```
