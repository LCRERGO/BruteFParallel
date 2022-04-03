package main

import (
	"crypto/md5"
	"encoding/hex"
	"fmt"
	"log"
	"os/exec"
	"sync"
)

var tests_str = []string{
	"PASS",
	"HPCMPP",
	"AAAAA",
	"AAAAAAAAAA",
	"0000000000",
}

func main() {
	var wg sync.WaitGroup
	wg.Add(len(tests_str))

	for test_num, test := range tests_str {
		hash := md5.Sum([]byte(test))
		digest := hex.EncodeToString(hash[:])

		fmt.Printf("Starting TEST %v with digest %v\n", test_num, digest)

		go func() {
			cmd := exec.Command("./password_bf")

			writ_pipe, err := cmd.StdinPipe()
			if err != nil {
				log.Fatal("ERR: Could not open stdin")
			}
			writ_pipe.Write([]byte(digest + "\n"))
			output, err := cmd.Output()
			if err != nil {
				log.Fatal("ERR: command could not be executed")
			}

			fmt.Println(string(output))
			wg.Done()
		}()
	}
	wg.Wait()
}
