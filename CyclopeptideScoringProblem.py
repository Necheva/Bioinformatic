def DataOfMass():
    table = {'G': 57,'A': 71,'S': 87,'P': 97,'V': 99,'T': 101,'C': 103,'I': 113,'L': 113,'N': 114,'D': 115,'K': 128,'Q': 128,'E': 129,'M': 131,'H': 137,'F': 147,'R': 156,'Y': 163,'W': 186 }
    return table
if __name__ == "__main__":
    Peptide = input()
    Spectrum = input()


    TmpDataMass = DataOfMass()


    initialData = []
    experimentalData = []
    index_first = 0
    index_second = 1
    index_fourth = 0
    index_fifth = 0
    index_sixth = 0
    index_seventh=0
    numberOfContents = 0


    while index_second < len(Peptide):
        index_count = 0
        while index_first < len(Peptide):
            ingex_third = 0
            tmp = 0
            while ingex_third < index_second:
                foo1=(index_first + ingex_third) % len(Peptide)
                foo=Peptide[(index_first + ingex_third) % len(Peptide)]
                tmp += int(TmpDataMass[Peptide[(index_first + ingex_third) % len(Peptide)]])
                ingex_third += 1
                index_count+=1
            initialData.append(tmp)
            index_first += 1
            if index_count >= 2:
                if index_second>=2:
                    index_count += -1
        index_first = 0
        index_second += 1
    if len(Peptide) != 0:
        tmp = 0
        for index_sixth in Peptide:
            tmp += int(TmpDataMass[index_sixth])
        initialData.append(tmp)
        initialData.append(0)
    initialData.sort()
    for v in Spectrum.split():
        experimentalData.append(int(v))
    for i in initialData:
        while (index_seventh < len(experimentalData)):
            if (i == experimentalData[index_seventh]):
                numberOfContents += 1
                index_seventh += 1
                break
            elif (i > experimentalData[index_seventh]):
                index_seventh += 1
            elif (i < experimentalData[index_seventh]):
                break
    print(numberOfContents)
