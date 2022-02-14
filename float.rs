use std::fs::File;
use std::io::{self, BufRead, Write};

fn calc(op: &str, args: Vec<f64>) -> f64 {
    match op {
        "+" => args[0] + args[1],
        "-" => args[0] - args[1],
        "*" => args[0] * args[1],
        "/" => args[0] / args[1],
        "sqrt" => args[0].sqrt(),
        _ => 0f64,
    }
}

fn main() -> io::Result<()> {
    let in_f = File::open("input.csv")?;
    let mut out_f = File::create("output_rust.csv")?;
    for line in io::BufReader::new(in_f).lines() {
        let _line = line?;
        let mut items = _line.split_whitespace();

        let op = items.next().unwrap();
        let arg_size = items.next().unwrap().parse::<usize>().unwrap();

        let mut args = Vec::<f64>::with_capacity(arg_size);
        for _ in 0..arg_size {
            args.push(items.next().unwrap().parse::<f64>().unwrap());
        }

        let c = calc(op, args);
        writeln!(out_f, "{:.100}", c)?;
    }
    Ok(())
}
