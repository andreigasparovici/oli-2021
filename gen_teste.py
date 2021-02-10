#!/usr/bin/env python3

import random
import shutil
import os

os.system('make')
os.system('mkdir -p teste')

# Generate first 3 tests
N_min = 5
N_max = 30

for i in range(3):
    N = random.randint(N_min, N_max)
    print(f'Test {i}: N = {N:5d}', end= ', ')
    open(f'teste/zid-{i}.in', 'w').write(str(N))

    shutil.copyfile(f'teste/zid-{i}.in', 'zid.in')
    os.system('exec/sol_dp')

    R = int(open('zid.out').read())
    print(f'Solution: {R}')

    shutil.copyfile('zid.out', f'teste/zid-{i}.ok')

    os.remove('zid.in')
    os.remove('zid.out')

# Generate the rest
N_min = 30
N_max = 5000

for i in range(3, 10):
    N = random.randint(N_min, N_max)
    print(f'Test {i}: N = {N:5d}', end=', ')
    open(f'teste/zid-{i}.in', 'w').write(str(N))

    shutil.copyfile(f'teste/zid-{i}.in', 'zid.in')
    os.system('exec/sol_dp')

    R = int(open('zid.out').read())
    print(f'Solution: {R}')

    shutil.copyfile('zid.out', f'teste/zid-{i}.ok')

    os.remove('zid.in')
    os.remove('zid.out')
