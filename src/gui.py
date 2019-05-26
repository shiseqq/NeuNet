import tkinter as tk
from tkinter import filedialog as fd
from tkinter import messagebox as mb
import os


def selectfile():
    root = tk.Tk()
    root.withdraw()
    file_path = fd.askopenfilename(title="Выбирите картинку в формате PNG",
                                   initialdir=os.path.expanduser("~"), filetypes=[("PNG files", "*.png")])
    root.destroy()
    return file_path