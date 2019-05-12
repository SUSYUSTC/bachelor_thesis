import re
f = open("./development.tex")
begin = True
for line in f:
    if re.match(r"\s*\$\$\s*", line):
        if begin:
            print(r"\begin{equation}")
            begin = False
        else:
            print(r"\end{equation}")
            begin = True
    else:
        print(line, end='')
