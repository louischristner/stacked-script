import re
import sys
import utils
import operations
import parserFuncs

# Read file line by line
def readFileByLine(filename, engine):
    with open(filename) as f:
        for line in f:
            parserFuncs.parseLine(line.rstrip(), engine)

# Main function
def main():
    engine = {
        'stack': [],
        'user_defined_operators': [],
        'numbers': re.compile('^\d+$'),
        'operators': {
            '+': operations.add,
            '-': operations.sub,
            '*': operations.mul,
            '/': operations.div,
            '%': operations.mod,
            '=': operations.cmp,
            '>': operations.gt,
            '<': operations.lt,
            '>=': operations.ge,
            '<=': operations.le,
            'dup': operations.dup,
            'over': operations.over,
            'drop': operations.drop,
            'nip': operations.nip,
            'swap': operations.swap,
            'print': operations.show,
            'times': operations.times,
            'loop': operations.loop,
            'if': operations.cond,
            'when': operations.when
        }
    }

    readFileByLine(sys.argv[len(sys.argv) - 1], engine)
    #utils.displayStack(engine['stack'])


if __name__ == "__main__":
    main()
