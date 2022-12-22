import numpy as np

class Par:

    cutAnd = " && "
    q0, q1 = "charge[0]", "charge[1]"
    t0, t1 = "tim[0]", "tim[1]"
    mtMcp = "( 0.5*(tim[2]+tim[3]) )"
    dtMcp = "( tim[3]-tim[2] )"
    mtSipm = "( 0.5*(tim[1]+tim[0]) )"
    dtSipm = "( tim[1]-tim[0] )"
    mcSipm = "( 0.5*(charge[1]+charge[0]) )"
    asymSipm = "( (charge[1]-charge[0])/(charge[1]+charge[0]) )"
    xCry = "cryPos[0]"
    yCry = "cryPos[1]"

    def cutRange(self, v1, c1, c2):
            return F"( {v1}>{c1} && {v1}<{c2} )"
        
    def cutRange2(self, v1, v2, c1, c2):
            return F"( {v1}>{c1} && {v1}<{c2} && {v2}>{c1} && {v2}<{c2} )"

    def __init__(self, run) -> None:

        self.fidlarge = np.zeros(4) 
        self.fidMcp = np.zeros(4)

        if (run == ""):
            self.fidlarge = [1,2,0,100]
            pass
        elif (run == "run530164"):
            self.fidlarge = [5.7, 6.7, 4.7, 5.6]
            self.qmin = 40
            self.qrange = [0, 500]
            self.qslices = np.linspace(40, 300, 7+1)
            self.gev_pc = 5/160
        elif (run == "run530167"):
            self.fidlarge = [5.9, 7.0, 4.7, 5.6]
            self.qmin = 40
            self.qslices = np.linspace(40, 300, 7+1)
            self.gev_pc = 5/160
        elif (run == "run530181"):
            self.fidlarge = [5.9, 7.0, 4.5, 5.5]
        elif (run == "run530178"):
            self.fidlarge = [5.9, 7.0, 4.5, 5.5]   

        self.fidmidx = 0.5*(self.fidlarge[0]+self.fidlarge[1])
        self.fidmidy = 0.5*(self.fidlarge[2]+self.fidlarge[3])
        self.fidhalfdx = 0.5*(self.fidlarge[1]-self.fidlarge[0])
        self.fidhalfdy = 0.5*(self.fidlarge[3]-self.fidlarge[2])

        self.fidLarge = F"({self.xCry}>{self.fidlarge[0]} && {self.xCry}<{self.fidlarge[1]} && {self.yCry}>{self.fidlarge[2]} && {self.yCry}<{self.fidlarge[3]})" 
        self.fidMiddle = F"({self.xCry}>{self.fidmidx-0.5*self.fidhalfdx} && {self.xCry}<{self.fidmidx+0.5*self.fidhalfdx} && {self.yCry}>{self.fidmidy-0.5*self.fidhalfdy} && {self.yCry}<{self.fidmidy+0.5*self.fidhalfdy})"

        self.fidUL = F"(cryPos[0]>{self.fidlarge[0]} && cryPos[0]<{self.fidmidx} && cryPos[1]>{self.fidmidy} && cryPos[1]<{self.fidlarge[3]})" 
        self.fidUR = F"(cryPos[0]>{self.fidmidx} && cryPos[0]<{self.fidlarge[1]} && cryPos[1]>{self.fidmidy} && cryPos[1]<{self.fidlarge[3]})" 
        self.fidDL = F"(cryPos[0]>{self.fidlarge[0]} && cryPos[0]<{self.fidmidx} && cryPos[1]>{self.fidlarge[2]} && cryPos[1]<{self.fidmidy})" 
        self.fidDR = F"(cryPos[0]>{self.fidmidx} && cryPos[0]<{self.fidlarge[1]} && cryPos[1]>{self.fidlarge[2]} && cryPos[1]<{self.fidmidy})" 
        self.fidU = F"(cryPos[0]>{self.fidlarge[0]} && cryPos[0]<{self.fidlarge[1]} && cryPos[1]>{self.fidmidy} && cryPos[1]<{self.fidlarge[3]})" 
        self.fidD = F"(cryPos[0]>{self.fidlarge[0]} && cryPos[0]<{self.fidlarge[1]} && cryPos[1]>{self.fidlarge[2]} && cryPos[1]<{self.fidmidy})" 
        self.fidL = F"(cryPos[0]>{self.fidlarge[0]} && cryPos[0]<{self.fidmidx} && cryPos[1]>{self.fidlarge[2]} && cryPos[1]<{self.fidlarge[3]})" 
        self.fidR = F"(cryPos[0]>{self.fidmidx} && cryPos[0]<{self.fidlarge[1]} && cryPos[1]>{self.fidlarge[2]} && cryPos[1]<{self.fidlarge[3]})" 

        self.fidQuadrants = [self.fidUL, self.fidUR, self.fidDL, self.fidDR]
        self.fidSides = [self.fidU, self.fidD, self.fidL, self.fidR]

        self.flrx = F"{self.fidlarge[0]},{self.fidlarge[1]}"
        self.flry = F"{self.fidlarge[2]},{self.fidlarge[3]}"
