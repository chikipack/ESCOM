import copy


class Automata:
    def __init__(self, nombreDelArchivo):
        self.nombreDelArchivo = nombreDelArchivo

        # esto es una lista de int
        self.estadosQ = self.obtenerEstados()

        # esto es una lista de int
        self.estadosF = self.obtenerEstadosFinales()

        # esto es un unico numero int
        self.estadoInicial = self.obtenerEstadoInicial()
        # esto es una lista de strings
        self.alfabeto = self.obtenerAlfabeto()

        self.transicionesDelta = self.obtenerDeltas()

    def leerContenidoTXT(self):
        with open(self.nombreDelArchivo) as f:
            contenido = f.readlines()
        return contenido

    def obtenerEstados(self):
        estadosQ = self.leerContenidoTXT()[0].rstrip()
        ESTADOS_Q = estadosQ.split(',')
        listaEstadosQ = []
        for estado in range(len(ESTADOS_Q)):
            listaEstadosQ.append(int(ESTADOS_Q[estado]))
        return listaEstadosQ

    def obtenerEstadosFinales(self):
        estadosFinales = self.leerContenidoTXT()[1].rstrip()
        ESTADOS_FINALES = estadosFinales.split(',')
        listaEstadosFinales = []
        for estado in range(len(ESTADOS_FINALES)):
            listaEstadosFinales.append(int(ESTADOS_FINALES[estado]))
        return listaEstadosFinales

    def obtenerEstadoInicial(self):
        estadoInicial = self.leerContenidoTXT()[2].rstrip()
        INICIAL = estadoInicial.split()
        return int(INICIAL[0])

    def obtenerAlfabeto(self):
        alfabeto = self.leerContenidoTXT()[3].rstrip()
        SIGMA = alfabeto.split(',')
        return SIGMA

    def obtenerDeltas(self):
        deltas = self.leerContenidoTXT()[4:]
        # asi es como obtiene la informacion:
        # ['0,E,1\n', '0,E,7\n', '1,E,2\n', '1,E,4\n', ... ]

        # luego las separamos para que se vean sin el \n
        # ['0,E,1', '0,E,7', '1,E,2', '1,E,4', ...]
        listaTransicionesDelta = []
        for i in range(len(deltas)):
            listaTransicionesDelta.append(deltas[i].rstrip())

        # finalmente las separamos en una lista de listas de string
        # [['0', 'E', '1'], ['0', 'E', '7'], ['1', 'E', '2'], ['1', 'E', '4'], ...]
        deltas_separados = []
        for item in range(len(listaTransicionesDelta)):
            deltas_separados.append(listaTransicionesDelta[item].split(','))
        return deltas_separados

    def cerraduraEpsilonInicial(self, estadoInicial):
        for delta in range(len(self.transicionesDelta)):
            for estado in range(len(estadoInicial)):
                if int(self.transicionesDelta[delta][0]) == estadoInicial[estado]:
                    if 'E' in self.transicionesDelta[delta][1]:
                        if self.transicionesDelta[delta][2] in nuevoEstadoInicial:
                            print(f'{self.transicionesDelta[delta][2]} ya esta en el conjunto')
                        else:
                            nuevoEstadoInicial.append(int(self.transicionesDelta[delta][2]))
        #print(f'nuevoEstadoInicial={nuevoEstadoInicial}')

    def mover(self, conjuntoARevisar, alfabeto):
        for letra in alfabeto:
            conjuntoTemp = []
            for estado in conjuntoARevisar:
                for transicion in self.transicionesDelta:
                    if letra == transicion[1]:
                        if estado == int(transicion[0]):
                            conjuntoTemp.append(int(transicion[2]))
                            print(conjuntoTemp)
            if conjuntoTemp == []:
                print(f'el conjunto {conjuntoARevisar} con {letra} nos lleva a error')
                ListaAux.append([conjuntoARevisar, letra, '0'])
            else:
                self.C_E(conjuntoTemp,letra,conjuntoARevisar)

        # conjuntosASacarleCerraduraE = []
        # for letra in alfabeto:
        #     conjuntoConLetra = []
        #     for estado in conjuntoARevisar:
        #         for transicion in self.transicionesDelta:
        #             if estado == int(transicion[0]):
        #                 if transicion[1] == letra:
        #                     conjuntoConLetra.append(int(transicion[2]))
        #                     print(estado, transicion)
        #                     if conjuntoConLetra in conjuntosASacarleCerraduraE:
        #                         print('ya esta')
        #                     else:
        #                         conjuntosASacarleCerraduraE.append(conjuntoConLetra)
        # print(f'soy funcion mover   {conjuntosASacarleCerraduraE}')
        # if conjuntosASacarleCerraduraE in parametroAMeterEnC_E:
        #     print(f'ya esta en el conjunto')
        # else:
        #     parametroAMeterEnC_E.append(conjuntosASacarleCerraduraE)
        # return parametroAMeterEnC_E

    def C_E(self, conjuntoEstados,letra, conjuntoARevisar):
        conjuntoARegresar = copy.deepcopy(conjuntoEstados)
        for estado in conjuntoARegresar:
            for transition in self.transicionesDelta:
                if estado == int(transition[0]):
                    if 'E' == transition[1]:
                        conjuntoARegresar.append(int(transition[2]))
        if conjuntoARegresar in listaDeNuevosEstados:
            print(f'{conjuntoARegresar} ya esta')
            ListaAux.append([conjuntoARevisar, letra, conjuntoARegresar])
            #haynuevo = False
        else:
            listaDeNuevosEstados.append(conjuntoARegresar)
            ListaAux.append([conjuntoARevisar,letra,conjuntoARegresar])

            #haynuevo = True
        # for conjunto in range(len(conjuntoARegresar)):
        #     for transicion in self.transicionesDelta:
        #         if int(transicion[0]) in conjuntoARegresar[conjunto]:
        #             if transicion[1] == 'E':
        #                 conjuntoARegresar[conjunto].append(int(transicion[2]))
        # if conjuntoARegresar in listaDeNuevosEstados:
        #     haynuevo = False
        # else:
        #     listaDeNuevosEstados.append(conjuntoARegresar)
        # print(f'soy metodo C_E  C_E() = {conjuntoARegresar}')
        # return conjuntoARegresar

automata1 = Automata('ThomToAFD0.txt')
nuevoEstadoInicial = [automata1.estadoInicial]
listaDeNuevosEstados = []
# empezamos sacando la C_E(0)
automata1.cerraduraEpsilonInicial(nuevoEstadoInicial)
listaDeNuevosEstados.append(nuevoEstadoInicial)

#haynuevo = True
#while haynuevo:
primerEstado = chr(65)
NuevosEstados = []
letra = 65
ListaAux = []
for estado in listaDeNuevosEstados:
    #for letra in automata1.alfabeto:
    automata1.mover(estado, automata1.alfabeto)
    NuevosEstados.append(chr(letra))
    letra += 1

    # for parametroAEnviar in parametroAMeterEnC_E:
    #     automata1.C_E(parametroAEnviar)
    #haynuevo = False
print(listaDeNuevosEstados)
print(NuevosEstados)
print(ListaAux)

for estado in ListaAux:
    if estado[0] in listaDeNuevosEstados:
        #print('webos')
        indice = listaDeNuevosEstados.index(estado[0])
        estado[0] = NuevosEstados[indice]
        if estado[2] == '0':
            estado[2] = '0'
        else:
            indice2 = listaDeNuevosEstados.index(estado[2])

            estado[2] = NuevosEstados[indice2]

print(ListaAux)
print('webos')


# paraUsarEnC_E = automata1.mover(nuevoEstadoInicial, automata1.alfabeto)
# CerraduraEpsilon = automata1.C_E(paraUsarEnC_E)
#
# for estado in CerraduraEpsilon:
#     paraUsarEnC_E2 = automata1.mover(estado, automata1.alfabeto)


