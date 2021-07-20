import utils

def parseArray(line_parts, index, engine):
    arrayElements = []

    while line_parts[index] != ']':
        arrayElements.append(line_parts[index])
        index += 1

    engine['stack'].append(' '.join(arrayElements))
    return index + 1

def parseFunction(line_parts, index, engine):
    functionElements = []

    functionName = line_parts[index]
    index += 1

    while line_parts[index] != ';':
        functionElements.append(line_parts[index])
        index += 1

    engine['operators'][functionName] = ' '.join(functionElements)
    engine['user_defined_operators'].append(functionName)
    return index + 1

# Parse line
def parseLine(line, engine):
    index = 0
    line_parts = line.split(' ')

    while index < len(line_parts):
        line_part = line_parts[index]

        # Comments
        if line_part == "'":
            break

        if line_part == '[':
            index = parseArray(line_parts, index + 1, engine)
            continue
        if line_part == ':':
            index = parseFunction(line_parts, index + 1, engine)
            continue
        else:
            match = engine['numbers'].match(line_part)
            if match is not None:
                engine['stack'].append(line_part)
            elif line_part in engine['operators']:
                if line_part in engine['user_defined_operators']:
                    parseLine(engine['operators'][line_part], engine)
                else:
                    engine['operators'][line_part](engine)
        index += 1