def funk(kwota) :
    nominaly = [500, 200, 100, 50, 20, 10, 5, 2, 1]
    uzyte = [0, 0, 0, 0, 0, 0, 0, 0, 0]
    for ind, nominal in enumerate(nominaly) :
        if (kwota >= nominal) :
            uzyte[ind] = kwota // nominal
            kwota = kwota - nominal * uzyte[ind]

    print(uzyte)

funk(83)