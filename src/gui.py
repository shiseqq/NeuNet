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


def wininp():
    s = ''

    def check(event):
        nonlocal s
        s = entry.get()
        if not s.isdigit() or int(s) > 9:
            tk.Tk().withdraw()
            mb.showerror("Ошибка", "Должна быть введена цифра")
        else:
            win.destroy()

    win = tk.Tk()
    win.title(" ")
    win.resizable(False, False)
    win.geometry("200x100")
    lable = tk.Label(win, height=1, text="Введите цифру").pack()
    entry = tk.Entry(win, width=20)
    entry.pack(pady=7)
    tk.Button(win, text="ОК", command=lambda: check(0)).pack()
    win.bind("<Return>", check)
    win.mainloop()

    if not s.isdigit() or int(s) > 9:
        return -1
    else:
        return int(s)
