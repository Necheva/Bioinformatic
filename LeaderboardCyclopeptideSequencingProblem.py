def DataOfMass():
    table = {'G': 57,'A': 71,'S': 87,'P': 97,'V': 99,'T': 101,'C': 103,'I': 113,'L': 113,'N': 114,'D': 115,'K': 128,'Q': 128,'E': 129,'M': 131,'H': 137,'F': 147,'R': 156,'Y': 163,'W': 186 }
    return table
TmpDataMass = DataOfMass()


if __name__ == "__main__":
    n = input()
    spectrum_str = input()
    Data_spectrum = list()
    for i in spectrum_str.split():
        Data_spectrum.append(int(i))
    aminoacids = set({'A', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'M', 'N', 'P', 'R', 'S', 'T', 'V', 'W', 'Y'})
    metka = True
    Leaderboard = set()
    LeaderPeptid = ''
    while (len(Leaderboard) != 0 or metka):
        metka = False
        remove_peptides = list()

        res = set()

        if (len(Leaderboard) == 0):
            res = aminoacids
        else:
            for i in Leaderboard:
                for j in aminoacids:
                    res.add(i + j)

        Leaderboard = res
        for peptide_iteration in Leaderboard:
            mass = 0
            for c in peptide_iteration:
                mass += TmpDataMass[c]
            previous_mass = 0
            Data_spectrum.sort()
            previous_mass = Data_spectrum[-1]
            if (mass == previous_mass):

                res_q = []
                for k in range(1, len(peptide_iteration)):
                    for i in range (len(peptide_iteration) - k + 1):
                        tmp = 0
                        for j in range(k):
                            tmp += int(TmpDataMass[peptide_iteration[i + j]])
                            res_q.append(tmp)
                    i = 0
                if len(peptide_iteration) != 0:
                    tmp = 0
                    for c in peptide_iteration:
                        tmp += int(TmpDataMass[c])
                    res_q.append(tmp)
                    res_q.append(0)
                res_q.sort()

                theoretical_Data = res_q
                experimental_Data = []
                for i in Data_spectrum:
                    experimental_Data.append(int(i))

                score = 0
                i = 0
                j = 0
                while (i < len(theoretical_Data) and j < len(experimental_Data)):
                    if (theoretical_Data[i] == experimental_Data[j]):
                        i += 1
                        j += 1
                        score += 1
                    else:
                        if (theoretical_Data[i] < experimental_Data[j]):
                            i += 1
                        else:
                            j += 1

                res_w = []
                for k in range(1, len(LeaderPeptid)):
                    for i in range(len(LeaderPeptid) - k + 1):
                        tmp = 0
                        for j in range(k):
                            tmp += int(TmpDataMass[LeaderPeptid[i + j]])
                        res_w.append(tmp)
                    i = 0
                if len(LeaderPeptid) != 0:
                    tmp = 0
                    for c in LeaderPeptid:
                        tmp += int(TmpDataMass[c])
                    res_w.append(tmp)
                    res_w.append(0)
                res_w.sort()

                theoretical_Data_1 = res_w
                experimental_Data_1 = []
                for i in Data_spectrum:
                    experimental_Data_1.append(int(i))

                score_1 = 0
                i = 0
                j = 0
                while (i < len(theoretical_Data_1) and j < len(experimental_Data_1)):
                    if (theoretical_Data_1[i] == experimental_Data_1[j]):
                        i += 1
                        j += 1
                        score_1 += 1
                    else:
                        if (theoretical_Data_1[i] < experimental_Data_1[j]):
                            i += 1
                        else:
                            j += 1

                if (score > score_1):
                    LeaderPeptid = peptide_iteration
            else:
                if (mass > previous_mass):
                    remove_peptides.append(peptide_iteration)
        for p in remove_peptides:
            Leaderboard.remove(p)

        res_fin = set()
        peptide_score_list = list()
        for ind in Leaderboard:

            res_e = []
            for k in range(1, len(ind)):
                for i in range(len(ind) - k + 1):
                    tmp = 0
                    for j in range(k):
                        tmp += int(TmpDataMass[ind[i + j]])
                    res_e.append(tmp)
                i = 0
            if len(ind) != 0:
                tmp = 0
                for c in ind:
                    tmp += int(TmpDataMass[c])
                res_e.append(tmp)
                res_e.append(0)
            res_e.sort()

            theoretical_Data_2 = res_e
            experimental_Data_0 = []
            for i in Data_spectrum:
                experimental_Data_0.append(int(i))

            score_0 = 0
            i = 0
            j = 0
            while (i < len(theoretical_Data_2) and j < len(experimental_Data_0)):
                if (theoretical_Data_2[i] == experimental_Data_0[j]):
                    i += 1
                    j += 1
                    score_0 += 1
                else:
                    if (theoretical_Data_2[i] < experimental_Data_0[j]):
                        i += 1
                    else:
                        j += 1
            peptide_score_list.append([ind, score_0])
        peptide_score_list = sorted(peptide_score_list, key=lambda element: element[1], reverse=True)
        min_length = min(len(peptide_score_list), int(n))
        metka_2 = True
        add_count = 0
        while (metka_2):
            if (add_count < min_length):
                res_fin.add(peptide_score_list[add_count][0])
                add_count += 1
            else:
                if (add_count < len(peptide_score_list) and peptide_score_list[min_length - 1][1] ==
                        peptide_score_list[add_count][1]):
                    res_fin.add(peptide_score_list[add_count][0])
                    add_count += 1
                else:
                    metka_2 = False

        Leaderboard = res_fin
    res_final_1 = LeaderPeptid
    res_str = ''
    tmp = ''
    for i in res_final_1:
        tmp += str(TmpDataMass[i]) + '-'
    res_str += tmp[:-1] + ' '
    print(res_str)

