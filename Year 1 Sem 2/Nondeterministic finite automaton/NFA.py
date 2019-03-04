import queue
class automaton:
    def __init__(self, type, input):
        self.states_count = int(input[0])
        self.letters_count = int(input[2])
        self.initial_state = int(input[4])
        self.final_state_count = int(input[5])
        final_states = input[6].split(" ")
        self.final_states = []
        for state in final_states:
            self.final_states.append(state)
        self.edges_count = int(input[7])
        self.edges=[]
        for i in range(0, self.edges_count + 1):
            self.edges.append([])
        for i in range(8,8 + self.edges_count):
            edge_string = input[i].split(" ")
            self.edges[int(edge_string[0])].append((edge_string[1],edge_string[2]))

class lNFA(automaton):
    def check_word(self, string):
        q = queue.Queue()
        q.put((self.initial_state,string))
        while q.empty() == False:
            pop = q.get()
            curent_state = int(pop[0])
            curent_string = str(pop[1])
            if self.__check_if_completed(curent_state,curent_string):
                return 1

            if len(self.edges[curent_state]) != 0:
                for edge in self.edges[curent_state]:
                    next_word = edge[0]
                    next_state = edge[1]
                    if next_word == '.':
                        a = (next_state,curent_string)
                        q.put(a)
                    else:
                        if next_word == curent_string[:1]:
                            a = (next_state,curent_string[1:])
                            q.put(a)
        return 0


    def __check_if_completed(self, curent_state, curent_string):
        for state in self.final_states:
            if state != '':
                if curent_state == int(state):
                    if curent_string == '' or curent_string == ' ':
                        return 1
        return 0



F = open("nfa.txt","r")
s = F.read()
s = s.split("\n")
nfa = lNFA('nfa',s)
a = nfa.edges[1]
a = a[0]
i = 8 + int(s[7])
n = int(s[i])
i+=1

for i in range(i,n + i):
    if nfa.check_word(s[i]) == 1:
        print("DA")
    else:
        print("NU")

