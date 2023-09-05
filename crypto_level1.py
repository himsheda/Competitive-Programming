def frequency_analysis(ciphertext):
    frequency = {}
    for letter in ciphertext:
        if letter.isalpha():
            if letter in frequency:
                frequency[letter] += 1
            else:
                frequency[letter] = 1
    frequency = dict(sorted(frequency.items(), key=lambda item: item[1], reverse=True))
    for letter, count in frequency.items():
        print(letter + ": " + str(count))
        


ciphertext = """Mewa wa mey twsam iepjoys gt mey ipbya.
Pa xgn iph ayy, meysy wa hgmewhr gt whmysyam wh mey iepjoys.
Agjy gt mey kpmys iepjoysa vwkk oy jgsy whmysyamwhr meph mewa ghy!
Mey iguy nayu tgs mewa jyaapry wa p awjfky anoamwmnmwgh iwfeys
wh vewie uwrwma epby oyyh aewtmyu ox 8 fkpiya. Mey fpaavgsu wa
"mxSrN03uwdd" vwmegnm mey dngmya."""
ciphertext=ciphertext.lower()
frequency_analysis(ciphertext)
decrypted=""
for letter in ciphertext:
    if letter=='p':
        decrypted +='A' # confirm
    elif letter=='a':
        decrypted +='S'
    elif letter=='w':
        decrypted +='I'
    elif letter=='h':
        decrypted +='N'
    elif letter=='y':
        decrypted +='E'
    elif letter=='m':
        decrypted +='T'
    elif letter=='e':
        decrypted +='H'
    elif letter=='s':
        decrypted +='R'
    elif letter=='r':
        decrypted +='G'
    elif letter=='g':
        decrypted +='O'
    elif letter=='t':
        decrypted +='F'
    elif letter=='x':
        decrypted +='Y'
    elif letter=='n':
        decrypted +='U'
    elif letter=='i':
        decrypted +='C'
    elif letter=='b':
        decrypted +='V'
    elif letter=='j':
        decrypted +='M'
    elif letter=='o':
        decrypted +='B'
    elif letter=='u':
        decrypted +='D'
    elif letter=='f':
        decrypted +='P'
    elif letter=='k':
        decrypted +='L'
    elif letter=='v':
        decrypted +='W'
    elif letter=='d':
        decrypted +='Q'
    else:
        decrypted +=letter

print(decrypted)


