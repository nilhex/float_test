run:
	go run float.go && \
	gcc -o float_c float.c && ./float_c && rm float_c && \
	rustc -o float_rs float.rs && ./float_rs && rm float_rs && \
	md5 output_*.csv

gen:
	python3 gen.py

check:
	md5 output_*.csv