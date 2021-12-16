# Como executar o projeto? 

Se você estiver utilizando uma distribuição Linux, instale os seguintes pacotes em sua máquina via terminal:
```
sudo apt-get install freeglut3 freeglut3-dev libglew-dev
sudo apt-gete install mesa-utils
```
Para saber como executar através do Windows, leia [aqui](https://github.com/valeriojr/monitoria-cg/blob/master/material/book.pdf).

Agora clone este repositório em sua máquina local, usando o seguinte comando:
```
https://github.com/audreyemmely/comp-grafica.git
```
Caso não tenha o Git instalado em sua máquina, consulte o [guia de instalação](https://git-scm.com/book/pt-br/v2/Come%C3%A7ando-Instalando-o-Git), ou você pode baixar o repositório em formato "zip", basta clicar no botão verde denominado "Code" (canto superior direito) e escolher a opção "Baixar ZIP". 
Depois disso, descompacte o arquivo e siga as instruções abaixo.

Usando o terminal, vá até o caminho onde a pasta está localizada em sua máquina (Ex.: /home/audrey/Área de Trabalho/comp-grafica/projetos)

Após acessar a pasta "comp-grafica/projetos" no terminal, você terá acesso aos arquivos dos projetos.

## Projeto Ola
Para executar o **projeto Ola**, utilize o seguinte comando: 
```
gcc projetoOla.c -o ola.out -lglut -lGL
./ola.out
```
É possível visualizar o efeito "ola" utilizando as letras 'q' 'w' 'e' 'r' 't' 'y' 'u' 'i' 'o' 'p' do teclado.

## Projeto Casa 3D
Para executar o **projeto Casa 3D**, utilize o seguinte comando: 
```
gcc casa3d.c -o casa3d.out -lglut -lGL
./casa3d.out
```
É possível visualizar a rotação em 360° utilizando a tecla 'r' do teclado.

## Projeto Catavento
Para executar o **projeto Catavento**, utilize o seguinte comando: 
```
gcc flor2catavento.c -o catavento.out -lglut -lGL
./catavento.out
```
É possível rotacionar para a direita utilizando a tecla 'd' do teclado utilizando a velocidade normal, para aumentar a velocidade utilizar a tecla 'f', para diminuir a velocidade utilizar a tecla 'g'. 

É possível rotacionar para a esquerda utilizando a tecla 'e' do teclado utilizando a velocidade normal, para aumentar a velocidade utilizar a tecla 'r', para diminuir a velocidade utilizar a tecla 't'. 

## Projeto Sistema Solar 
Para executar o **projeto Sistema Solar**, utilize o seguinte comando: 
```
gcc sistemaSolar.c -o sistemaSolar.out -lglut -lGL -lGLU
./sistemaSolar.out
```

