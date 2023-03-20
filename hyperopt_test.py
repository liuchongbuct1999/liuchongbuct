import hyperopt
from hyperopt import hp, fmin, tpe, Trials, partial, rand
from hyperopt.early_stop import no_progress_loss
import numpy as np
from matplotlib import pyplot as plt

# hyperopt是可用的，tpe 是基于高斯混合回归过程的


#你好git
# 目标函数的输入必须是字典的形式
def fn(params):
    x = params['x']
    y = params['y']
    fenzi = (2 * x + 1) * (y + 1)
    fenmu = 2 * x ** 2 + 5 * y ** 2 + 7
    return  (-1)* fenzi / fenmu


space = {
    'x': hp.uniform('x', 0, 5),
    'y': hp.uniform('y', 0, 5),
}


def param_hyperopt(max_evals=100):
    # 保存迭代过程
    trials = Trials()
    # 设置提前停止
    early_stop_fn = no_progress_loss(100)
    # 定义代理模型
    algo = partial(tpe.suggest, n_startup_jobs=20, n_EI_candidates=50)
    params_best = fmin(
        #目标函数
        fn=fn,
        #参数空间
        space=space,
        # 使用算法
        algo=algo,
        # 可以选择随机网格
        # algo=rand.suggest,
        #设置迭代次数
        max_evals=max_evals,
        #搜获过程中是否打印信息
        verbose=True,
        # 保存迭代过程
        trials = trials,
        # 多少次效果没有提升直接结束迭代
        early_stop_fn = early_stop_fn
    )

    # 打印最优参数，fmin会自动打印最佳分数
    print("\n", "\n", "best params: ", params_best,
          "\n")
    return params_best, trials




params_best, trials = param_hyperopt(500)
print(params_best)
X = []
Y = []

for i in range(len(trials.trials)):
    x = (trials.trials[i]['misc']['vals']['x'][0])
    y = (trials.trials[i]['misc']['vals']['y'][0])
    X.append(float(x))
    Y.append(float(y))

print(X)
print(Y)

# plt.scatter(X,Y)
# plt.show()

print(trials.vals["x"])
print(trials.vals["y"])
print(trials.losses())

plt.scatter(trials.vals["x"],trials.losses())
plt.scatter(trials.vals["y"],trials.losses())
plt.show()







