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

Para executar o projeto Ola, utilize o seguinte comando: 
```
gcc projetoOla.c -o ola.out -lglut -lGL
./ola.out
```
