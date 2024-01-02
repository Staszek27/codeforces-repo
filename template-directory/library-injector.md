## data-structures

```bash {cmd}
python3 inject.py data-structures/sparse-table.cpp >> logs.txt
```

```bash {cmd}
python3 inject.py data-structures/tree-lazy.cpp >> logs.txt
```

```bash {cmd}
python3 inject.py data-structures/tree-query-point.cpp >> logs.txt
```

```bash {cmd}
python3 inject.py data-structures/tree-fenwick.cpp >> logs.txt
```

```bash {cmd}
python3 inject.py data-structures/tree-query-seg.cpp >> logs.txt
```
## others

```bash {cmd}
python3 inject.py others/geo.cpp >> logs.txt
```

```bash {cmd}
python3 inject.py others/cht.cpp >> logs.txt
```
## math

```bash {cmd}
python3 inject.py math/math-factors.cpp >> logs.txt
```

```bash {cmd}
python3 inject.py math/math-mod.cpp >> logs.txt
```

```bash {cmd}
python3 inject.py math/math-newton.cpp >> logs.txt
```
## graphs structures

```bash {cmd}
python3 inject.py graphs/structures/multiset-weighed.cpp >> logs.txt
```

```bash {cmd}
python3 inject.py graphs/structures/regular-weighed.cpp >> logs.txt
```

```bash {cmd}
python3 inject.py graphs/structures/multiset.cpp >> logs.txt
```

```bash {cmd}
python3 inject.py graphs/structures/regular.cpp >> logs.txt
```
## graphs algos

```bash {cmd}
python3 inject.py graphs/algos/dijkstra.cpp >> logs.txt
```

```bash {cmd}
python3 inject.py graphs/algos/bfs.cpp >> logs.txt
```

```bash {cmd}
python3 inject.py graphs/algos/dsu-and-kruskal.cpp >> logs.txt
```

```bash {cmd}
python3 inject.py graphs/algos/tree-prep.cpp >> logs.txt
```


## tools

### clean libraries in the current file

```bash {cmd}
python3 inject.py  -clean >> logs.txt
```

### show lib

```bash {cmd}
python3 inject.py  -ls
```

### update markdown

```bash {cmd}
cd ~/Documents/codeforces/codeforces-repo && python3 library-injector-gen.py

```

### update files in the current directory

```bash {cmd}
P=$(pwd)
cd ~/Documents/codeforces/codeforces-repo
./preparer.sh $P reset
```

