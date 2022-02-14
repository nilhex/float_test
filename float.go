package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func calc(op string, args []float64) float64 {
	switch op {
	case "+":
		return args[0] + args[1]
	case "-":
		return args[0] - args[1]
	case "*":
		return args[0] * args[1]
	case "/":
		return args[0] / args[1]
	case "sqrt":
		return math.Sqrt(args[0])
	}
	return 0
}

func main() {
	in, _ := os.Open("input.csv")
	defer in.Close()
	out, _ := os.Create("output_golang.csv")
	defer out.Close()

	scanner := bufio.NewScanner(in)

	for scanner.Scan() {
		items := strings.Split(scanner.Text(), " ")

		op := items[0]
		size, _ := strconv.Atoi(items[1])

		args := make([]float64, size)
		for i := range args {
			args[i], _ = strconv.ParseFloat(items[i+2], 64)
		}

		c := calc(op, args)

		out.Write([]byte(fmt.Sprintf("%.100f\n", c)))
	}
}
