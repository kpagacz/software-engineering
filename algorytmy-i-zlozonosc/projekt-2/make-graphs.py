import pandas as pd 
import numpy as np 
import seaborn as sns 
import matplotlib.pyplot as plt  

results_file = "results.csv"
data = pd.read_csv(results_file, header=None)
data.columns = ["Drzewo", "Powieść", "Ciąg znaków", "Głębokość", "Liczba wystąpień"]
data["Powieść"] = data["Powieść"].map(lambda x : x.lstrip("novels/").rstrip(".txt"))

sns.set_context("talk", font_scale=1.2)
# głębokość od powieści z podziałem na drzewa
_ = plt.figure(figsize=(19, 12))
# _ = sns.stripplot(data = data, x = "Powieść", y = "Głębokość", hue = "Drzewo", dodge=True)
_ = sns.pointplot(data = data, x = "Powieść", y = "Głębokość", hue = "Drzewo", dodge=True, join=False, ci="sd")
# _ = sns.violinplot(data = data, x = "Powieść", y = "Głębokość", hue = "Drzewo", dodge=True)
_ = plt.title("Głębokość szukanego słowa w zależności od powieści")
_ = plt.ylim(bottom=0)
plt.savefig("wykresy/glebokosc-powiesc.png", bbox_inches="tight")
plt.close()

# głębokość w zaleznosci od liczby wystapien
_ = plt.figure(figsize=(19,12))
_ = sns.lmplot(data = data, x = "Liczba wystąpień", y = "Głębokość", hue = "Drzewo", col="Powieść", col_wrap=2, markers=["o", "x", "1"], scatter_kws={"s" : 25})
plt.savefig("wykresy/glebokosc-liczba-wystapien.png", bbox_inches="tight")
plt.close()
