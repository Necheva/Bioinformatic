def DataOfMass():
    table = {'G': 57,'A': 71,'S': 87,'P': 97,'V': 99,'T': 101,'C': 103,'I': 113,'L': 113,'N': 114,'D': 115,'K': 128,'Q': 128,'E': 129,'M': 131,'H': 137,'F': 147,'R': 156,'Y': 163,'W': 186 }
    return table
if __name__ == "__main__":
    Spectrum = input()
    Peptides = set()
    metka_first = True
    current_position=0
    TmpDataMass = DataOfMass()
    Data_spectrum = []
    for i in Spectrum.split():
        Data_spectrum.append(int(i))
    Data_aminoacids = set({'A', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'M', 'N', 'P', 'R', 'S', 'T', 'V', 'W', 'Y'})
    result_of_work = []
    while (len(Peptides) != 0 or metka_first):
        metka_first = False
        remove_peptides = []

        res_1 = set()
        if (len(Peptides) == 0):
            res_1 = Data_aminoacids
        else:
            for i in Peptides:
                for j in Data_aminoacids:
                    res_1.add(i + j)
        Peptides=res_1
        for peptide_iteration in Peptides:
            mass = 0
            for c in peptide_iteration:
                mass += TmpDataMass[c]
            per_mass=0
            Data_spectrum.sort()
            previous_mass= Data_spectrum[-1]
            if (mass == previous_mass):

                res_2 = []
                i = 0
                k = 1
                while k < len(peptide_iteration):
                    while i < len(peptide_iteration):
                        j = 0
                        tmp = 0
                        while j < k:
                            current_position=(i + j) % len(peptide_iteration)
                            tmp += int(TmpDataMass[peptide_iteration[current_position]])
                            j +=1
                        res_2.append(tmp)
                        i += 1
                    i = 0
                    k += 1
                tmp = 0
                for c in peptide_iteration:
                    tmp += int(TmpDataMass[c])
                res_2.append(tmp)
                res_2.append(0)
                res_2.sort()

                if (res_2 == Data_spectrum):
                    result_of_work.append(peptide_iteration)
                remove_peptides.append(peptide_iteration)
            else:
                metka_second=True

                res_3 = []
                ind = 0
                kind = 1
                while kind < len(peptide_iteration):
                    while ind < len(peptide_iteration) - kind + 1:
                        j = 0
                        tmp_2 = 0
                        while j < kind:
                            tmp_2 += int(TmpDataMass[peptide_iteration[ind + j]])
                            j += 1
                        res_3.append(tmp_2)
                        ind += 1
                    ind = 0
                    kind += 1
                if len(peptide_iteration) != 0:
                    tmp_2 = 0
                    for c in peptide_iteration:
                        tmp_2 += int(TmpDataMass[c])
                    res_3.append(tmp_2)
                    res_3.append(0)
                res_3.sort()

                for z in res_3:
                    if z not in Data_spectrum:
                        metka_second= False
                if metka_second==False:
                    remove_peptides.append(peptide_iteration)
        for peptide_iteration in remove_peptides:
            Peptides.remove(peptide_iteration)
    result_of_work.sort()
    res_str = ''
    for peptid in result_of_work:
        tmp = ''
        for i in peptid:
            tmp += str(TmpDataMass[i]) + '-'
        res_str += tmp[:-1] + ' '
    print(res_str)
