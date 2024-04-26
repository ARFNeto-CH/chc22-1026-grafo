import time
import pyautogui as gui
import netifaces as net
from os import path
from os import getenv

class Roteador:

  def __init__( self, endereco, senha, pasta, roteiro ):
    self.address = endereco
    self.password = senha 
    self.folder = pasta
    self.roteiro = roteiro
    
  def Show(self):
    print("Roteador:", self.address )
    print("   senha: ", self.password )
    print("   pasta: ", self.folder )
    print("Roteiro tem ", len(self.roteiro), "passos:")

  def Check(self):
    ok = 0
    for item in self.roteiro:
        if ( path.exists(self.folder + '/' + item)):
            ok += 1
    if (ok != len(self.roteiro)): return False
    print("Check: Todos os arquivos presentes")
    senha = getenv(self.password,default="Nao encontrado")
    if ( senha == "Nao encontrado"):
        print("Senha nao encontrada")
        return False
    self.password = senha
    print("Check: Senha de acesso definida para",self.address)
    return True

  def Step(self,img,action="click",\
    btn="left",    attempts=3,     confidence=.8):
    att = 1 # first time
    image = self.folder + '\\' + img
    while (att<attempts):
        location = gui.locateCenterOnScreen(image,confidence=confidence )
        if ( location == None ):
           time.sleep(1.2) # retry time
           att += 1 # count this
           continue
        print(image," found!")
        if ( action == "move"):
            gui.moveTo(location)
        else:
            if ( action == "click"):
                gui.click(location.x,location.y, button=btn)
            else:
                pass # action none
        return att
    # estourou o numero de tentativas
    if ( location == None ):
      print(image," not found!")
      return 0
    return att
  
  def Automate(self):
    if (self.Check()):
      print("Reiniciando equipamento em",self.address)
    else:
      print("Erro: Faltam arquivos. Cancelando...")
      return False
    save =  gui.PAUSE
    gui.PAUSE = 1
    prefix = "Chrome http://" 
    suffix = "  --new-window\n"
    arg = prefix+self.address+suffix
    gui.hotkey("win","r")
    gui.typewrite(arg)
    time.sleep(1.)
    gui.hotkey("F11")
    gui.typewrite(self.password)
    gui.hotkey("ENTER")
    time.sleep(1.)
    # session is open
    steps = len(self.roteiro)
    done = 0
    for item in self.roteiro:
        res = self.Step(item)
        time.sleep(1.3)
        if ( res != 1 ):
            break
        done +=1
    if ( done == steps ):
        print("RESET OK!")
    else:
        print("Erro no RESET!")
    time.sleep(0.5)
    gui.hotkey("alt","F4") # end session

  def Gateway(self):
    return net.gateways()['default'][2][0];

#
# RESET VIVO
# 
class VIVO(Roteador):
  def abre_sessao(self):
    save =  gui.PAUSE
    gui.PAUSE = 1
    prefix = "Chrome http://" 
    suffix = "  --new-window\n"
    arg = prefix+self.address+suffix
    gui.hotkey("win","r")
    gui.typewrite(arg)
    time.sleep(5.0)
    gui.hotkey("F11")
    # esta online?
    res = self.Step(self.roteiro[0],action="none")
    # retorna 1 se ja esta online
    if ( res == 1):
        return True
    # esta na tela em que pede a senha?
    res = self.Step(self.roteiro[1])
    # esta na tela de login
    if ( res == 1):
        gui.hotkey("TAB")
        gui.typewrite("admin")
        gui.hotkey("TAB")
        gui.typewrite(self.password)
        res = self.Step(self.roteiro[2])
        gui.PAUSE = save
        if ( res == 0):
            return False
        return True
    # nao esta na tela de login entao 
    # precisa abrir o prompt de login
    res = self.Step(self.roteiro[3])
    if ( res == 0 ):
        return False # deu pau
    res = self.Step(self.roteiro[4])
    if ( res == 0 ):
        return False # deu pau
    # ok deve estar de volta na tela de login    
    res = self.Step(self.roteiro[1])
    # esta na tela de login
    # ok agora deve ter a tela
    gui.hotkey("TAB")
    gui.typewrite("admin")
    gui.hotkey("TAB")
    gui.typewrite(self.password)
    res = self.Step(self.roteiro[2])
    if ( res == 0 ):
        return False 
    gui.PAUSE = save
    return True
     
  def Automate(self,simulado=False): 
    
    if ( simulado ):
        print("Simulado VIVO: vai retornar antes de reiniciar")
        act = "none"
    else:
        print("ATENCAO: vai reiniciar o servico da VIVO")
        act = "click"

    if (self.Check()):
      print("Reiniciando equipamento em",self.address)
    else:
      print("Erro: Faltam arquivos. Cancelando...")
      return False

    res = self.abre_sessao()
    if ( not res ):
        print("Erro ao tentar abrir sessao")
        return False

    print("Sessao aberta no roteador. Prosseguindo em 6s...")
    time.sleep(6.0)

    for i in range (3,6):
        res = self.Step(self.roteiro[i]);
        if ( res == 0):
            break
    time.sleep(2.0)
    res = self.Step(self.roteiro[6],act);
    if ( res == 1):
        print("Posicionado no RESET")
    else:
        print("Nao encontrou botao RESET")
    gui.hotkey("F11")
    time.sleep(3)
    gui.hotkey("alt","F4") # end session
    return True


class AX10(Roteador):  
  def Automate(self):

    if (self.Check()):
      print("Reiniciando TP-Link AX10 em",self.address)
    else:
      print("Erro: Faltam arquivos. Cancelando...")
      return False
    save =  gui.PAUSE
    gui.PAUSE = 1
    prefix = "Chrome http://" 
    suffix = "  --new-window\n"
    arg = prefix+self.address+suffix
    gui.hotkey("win","r")
    gui.typewrite(arg)
    time.sleep(1.)
    gui.hotkey("F11")

    # tenta a tela de login. Nem sempre acessa
    # se nao estiver diretamente conectado ao
    # aparelho
    res = self.Step(self.roteiro[0],action="none")
    if ( res == 0 ):
        print("Sem acesso ao login!")
        time.sleep(2.0)
        gui.hotkey("F11")
        gui.hotkey("alt","F4") # end session
        return False

    res = self.Step(self.roteiro[1])
    if ( res == 0 ):
        print("Sem acesso ao login!")
        time.sleep(2.0)
        gui.hotkey("F11")
        gui.hotkey("alt","F4") # end session
        return False
    gui.typewrite(self.password)
    gui.hotkey("ENTER")
    # session is open
    done = 2
    steps = len(self.roteiro)
    for item in range(2,steps):
        res = self.Step(self.roteiro[item])
        time.sleep(1.3)
        if ( res < 1 ):
            break
        done +=1
    if ( done == steps ):
        print("RESET OK!")
    else:
        print("Erro no RESET!")
    time.sleep(2.0)
    gui.hotkey("F11")
    gui.hotkey("alt","F4") # end session


#
# RESET do gateway CLARO NET
# 
class CLARO(Roteador):

  def __init__( self, arquivo, pasta, roteiro ):
    gateway = self.Gateway();
    print ( "Gateway: ", gateway);
    with open(arquivo, encoding="utf-8") as f:
        self.usuario = f.readline().split("\n")[0];
        self.password = f.readline().split("\n")[0];
    print( "Usuario: ", self.usuario );
    print( "Senha: ", self.password );
    print( "pasta: ", pasta);
    print( "roteiro: ", roteiro);
    super(CLARO,self).__init__( gateway, self.password, pasta, roteiro)

  def Check(self):
    ok = 0
    for item in self.roteiro:
        if ( path.exists(self.folder + '/' + item)):
            ok += 1
    if (ok != len(self.roteiro)): return False
    print("Check: Todos os arquivos presentes")
    return True

  def abre_sessao(self):
    save =  gui.PAUSE
    gui.PAUSE = 1
    prefix = "Chrome http://" 
    suffix = "  --new-window\n"
    arg = prefix+self.address+suffix
    gui.hotkey("win","r")
    gui.typewrite(arg)
    time.sleep(5.0)
    gui.hotkey("F11")
    # esta online?
    res = self.Step(self.roteiro[0],action="click")
    # usa TAB shift TAB para voltar para digitar o usuario
    # retorna 1 se ja esta online

    print( "Usuario: ", self.usuario );
    print( "Senha: ", self.password );

    gui.hotkey("TAB")
    gui.hotkey("SHIFT","TAB")
    gui.typewrite(self.usuario);
    gui.hotkey("TAB")
    gui.typewrite(self.password);
    res = self.Step(self.roteiro[1],action="click");
    return res;
     
  def Automate(self,simulado=False): 
    
    if ( simulado ):
        print("Simulado CLARO")
        act = "none"
    else:
        print("ATENCAO: vai reprogramar o ROTEADOR da CLARO NET")
        act = "click"

    if (self.Check()):
      print("Reiniciando equipamento em",self.address)
    else:
      print("Erro: Faltam arquivos. Cancelando...")
      return False

    res = self.abre_sessao()
    if ( not res ):
        print("Erro ao tentar abrir sessao")
        return False

    print("Sessao aberta no roteador. Prosseguindo em 3s...")
    time.sleep(3.0)

    res = self.Step(self.roteiro[2]);
    if ( res == 0):
        return False;
    print( self.roteiro[2], "ok");

    res = self.Step(self.roteiro[3]);
    if ( res == 0):
        return False;
    print( self.roteiro[3], "ok");

    # define o endereco do gateway
    gui.hotkey("TAB")
    gui.hotkey("TAB")
    gui.hotkey("TAB")
    gui.typewrite('10'); # endereco DHCP
    gui.hotkey("TAB");
    gui.typewrite('0');
    gui.hotkey("TAB");
    gui.typewrite('138');
    gui.hotkey("TAB");
    gui.typewrite('1'); # inicio DHCP 

    # muda o tempo do lease do dhcp
    gui.hotkey("TAB")
    gui.hotkey("TAB")
    gui.hotkey("TAB")
    gui.typewrite('224');
 
    gui.hotkey("TAB")
    gui.typewrite('420'); 
    
    res = self.Step(self.roteiro[4]);
    if ( res == 0):
        return False;
    print( self.roteiro[4], "ok");
    
    if ( simulado  ):
        print("Saindo da simulacao...")
        return True

    res = self.Step(self.roteiro[5]);
    if ( res == 0):
        print("Erro ao aplicar ajustes...")
        return False;

    print( self.roteiro[6], "tentando...");
    res = self.Step(self.roteiro[6]);
    if ( res == 0):
        print("Erro ao sair da interface:...")
        return False;

    print( self.roteiro[6], "ok");
    time.sleep(3.0)
    gui.hotkey("F11")
    time.sleep(4)
    gui.hotkey("alt","F4") # end session
    return True



