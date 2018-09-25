import math


def dH(a1, d1, a2, d2, h2):
    """
    a1 : attack of figure1
    d1: defense
    """
    return math.floor((a1 - d2) / h2) * (a2 - d1)


def main():
    pass


if __name__ == '__main__':
    main()
