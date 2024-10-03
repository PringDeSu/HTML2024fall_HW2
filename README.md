# HTML Home Work 2 Code
### B13902149 高翊恩
### last edit: 2024/10/03
---

## Main script (PLA algorithm)
```
g++ -std=c++17 ./main.cpp
./a.out output_1.txt
g++ -std=c++17 -D DECISION_STUMP_MODIFIED ./main.cpp
./a.out output_2.txt
```

## Generate Figure
```
python3 -m venv ./python
./python/bin/pip install matplotlib PyQt6
./python/bin/python ./python/scatter_chart.py b figure_11.png < output_1.txt
./python/bin/python ./python/scatter_chart.py r figure_12.png < output_2.txt
```
