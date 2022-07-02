from autom_scr import \
    reset_DLINK, \
    reset_VIVO

print(
    "Varanda:  Tempos ",
    reset_DLINK("192.168.15.2","2017-iso9001D\n")
    )

print(
    "Quarto: Tempos Attempts ",
    reset_DLINK("192.168.15.3","2017-iso9001D\n")
    )

print(
    "Roteador VIVO Tempos: attempts ",
    reset_VIVO("192.168.15.1","231A-iso9001V")
    )

exit(0)
