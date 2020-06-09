package main

/*import (
	"fmt"
	"io"
	"os"

	"github.com/hajimehoshi/go-mp3"
	"github.com/hajimehoshi/oto"
)

func playSound(path string) error {
	file, err := os.Open(path)
	myErr(err)
	defer file.Close()

	decoder, err := mp3.NewDecoder(file)
	myErr(err)

	context, err := oto.NewContext(decoder.SampleRate(), 2, 2, 8192)
	myErr(err)
	defer context.Close()

	player := context.NewPlayer()
	defer player.Close()

	fmt.Printf("Length: %d[bytes]\n", decoder.Length())

	if _, err := io.Copy(player, decoder); err != nil {
		return err
	}
	return nil
}

func myErr(err error) error {
	if err != nil {
		return err
	}

	return nil
}*/
