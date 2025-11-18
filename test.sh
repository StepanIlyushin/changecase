#!/bin/sh
./changecase -L tests/test1.txt out.txt && (cmp out.txt tests/test1-L.txt || exit 1)
./changecase -U tests/test1.txt out.txt && (cmp out.txt tests/test1-U.txt || exit 1)
./changecase -G tests/test1.txt out.txt && (cmp out.txt tests/test1-G.txt || exit 1)
./changecase -T tests/test1.txt out.txt && (cmp out.txt tests/test1-T.txt || exit 1)