#!/bin/sh
./change -L tests/test1.txt out.txt && (cmp out.txt test1-L.txt || exit 1)
./change -U tests/test1.txt out.txt && (cmp out.txt test1-U.txt || exit 1)
./change -G tests/test1.txt out.txt && (cmp out.txt test1-G.txt || exit 1)
./change -T tests/test1.txt out.txt && (cmp out.txt test1-T.txt || exit 1)
./change -R tests/test1.txt out.txt && (cmp out.txt test1-R.txt || exit 1)