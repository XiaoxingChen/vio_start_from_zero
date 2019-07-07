import os
import sys
import matplotlib.pyplot as plt
import re

def ExecuteCurveFitting():
    os.chdir(os.path.dirname(os.path.realpath(__file__)))
    exec_file = '../CurveFitting_LM/build/app/testCurveFitting'
    log_filename = 'output.log'
    os.system(exec_file + ' > ' + log_filename)
    return log_filename

def ExtractData(log_filename):
    text_file = open(log_filename, 'r').read()
    pattern = 'iter:\s(.*?) , .*Lambda=\s(.*?)$'
    match_list = re.findall(pattern, text_file, flags=re.MULTILINE)    
    i = [int(p[0]) for p in match_list]
    lam = [float(p[1]) for p in match_list]
    return i, lam

if __name__ == "__main__":
    print('start')
    log_filename = ExecuteCurveFitting()
    i, lam = ExtractData(log_filename)
    plt.plot(i, lam, 'o-')
    plt.yscale('log')
    plt.ylabel('Lambda')
    plt.xlabel('Iteration')
    plt.title('Damper Factor Curve')
    plt.grid(1)
    plt.show()
    