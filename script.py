import subprocess

orderFile = open("order.txt","r")
outputFile = open("output.txt", "w")
lines = orderFile.readlines()

orderFile.close()

outputFile.writelines("version              n    time(s)  Normalized(ns)\n")
for i in range(len(lines)):
    orderPrt = lines[i].split(" ")
    command = "./{type}{version} {size}".format(type= orderPrt[4], version = orderPrt[3].lower(), size = orderPrt[5])

    result = subprocess.run(command.split(" "), stdout=subprocess.PIPE)

    output = str(result.stdout)
    outputs = output.replace("b'","").replace("'","").split('\\n')

    for j in range(1,len(outputs)):
        outputFile.writelines("{out}\n".format(out = outputs[j]))

outputFile.close()


"""result = subprocess.run(input("put command: ").split(" "), stdout=subprocess.PIPE)
file = open(input("output file name: "), "w")
output = str(result.stdout)
outputs = output.replace("b'","").replace("'","").split('\\n')
print(outputs)
for i in range(len(outputs)):
    file.writelines("{line}\n".format(line = outputs[i]))
file.close()"""