import utils
import parserFuncs

def add(engine):
    v2 = engine['stack'].pop()
    v1 = engine['stack'].pop()
    engine['stack'].append(str(int(v1) + int(v2)))

def sub(engine):
    v2 = engine['stack'].pop()
    v1 = engine['stack'].pop()
    engine['stack'].append(str(int(v1) - int(v2)))

def mul(engine):
    v2 = engine['stack'].pop()
    v1 = engine['stack'].pop()
    engine['stack'].append(str(int(v1) * int(v2)))

def div(engine):
    v2 = engine['stack'].pop()
    v1 = engine['stack'].pop()
    engine['stack'].append(str(int(int(v1) / int(v2))))

def mod(engine):
    v2 = engine['stack'].pop()
    v1 = engine['stack'].pop()
    engine['stack'].append(str(int(int(v1) % int(v2))))

def cmp(engine):
    v2 = engine['stack'].pop()
    v1 = engine['stack'].pop()
    result = 'true' if v1 == v2 else 'false'
    engine['stack'].append(result)

def gt(engine):
    v2 = engine['stack'].pop()
    v1 = engine['stack'].pop()
    result = 'true' if int(v1) > int(v2) else 'false'
    engine['stack'].append(result)

def lt(engine):
    v2 = engine['stack'].pop()
    v1 = engine['stack'].pop()
    result = 'true' if int(v1) < int(v2) else 'false'
    engine['stack'].append(result)

def ge(engine):
    v2 = engine['stack'].pop()
    v1 = engine['stack'].pop()
    result = 'true' if int(v1) >= int(v2) else 'false'
    engine['stack'].append(result)

def le(engine):
    v2 = engine['stack'].pop()
    v1 = engine['stack'].pop()
    result = 'true' if int(v1) <= int(v2) else 'false'
    engine['stack'].append(result)

def dup(engine):
    engine['stack'].append(engine['stack'][len(engine['stack']) - 1])

def over(engine):
	engine['stack'].append(engine['stack'][len(engine['stack']) - 2])

def drop(engine):
	engine['stack'].pop();

def nip(engine):
	tmp_v = engine['stack'].pop()
	engine['stack'].pop()
	engine['stack'].append(tmp_v)

def swap(engine):
	v2 = engine['stack'].pop()
	v1 = engine['stack'].pop()
	engine['stack'].append(v2)
	engine['stack'].append(v1)

def show(engine):
    print(engine['stack'].pop())

def times(engine):
    v2 = engine['stack'].pop()
    v1 = engine['stack'].pop()
    for index in range(0, int(v1)):
        parserFuncs.parseLine(v2, engine)

def loop(engine):
    v = engine['stack'].pop();
    while True:
        parserFuncs.parseLine(v, engine)
        if engine['stack'].pop() == 'true':
            break

def cond(engine):
    v3 = engine['stack'].pop()
    v2 = engine['stack'].pop()
    v1 = engine['stack'].pop()
    if v1 == 'true':
        parserFuncs.parseLine(v2, engine)
    else:
        parserFuncs.parseLine(v3, engine)

def when(engine):
    v2 = engine['stack'].pop()
    v1 = engine['stack'].pop()
    if v1 == 'true':
        parserFuncs.parseLine(v2, engine)
