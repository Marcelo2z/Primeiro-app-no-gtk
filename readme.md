#### Projeto de começo;
#### Comunicação entre Interface e Arduino;

### Abre uma janela onde;

----------------------------------------------------------------
## Contem um titulo sobre o app;

----------------------------------------------------------------
## Contem titulo e subtitulo com o estdado do LED;

----------------------------------------------------------------
## Contem 2 botões:
    Um para Ligar o LED;
    Um para Desligar o LED;

----------------------------------------------------------------
### Tecnologias utilizadas;
- C++
- GTK4
- VS Code
- MSYS2

----------------------------------------------------------------
### Como compilar;
```bash
g++ main.cpp -o app.exe $(pkg-config --cflags --libs gtk4)