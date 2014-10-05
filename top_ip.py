#tricks on big data with python mainly implement the algos from http://blog.csdn.net/v_july_v/article/details/7382693

def generate_ip():
    from time import ctime
    import random
    print(ctime())
    for i in range(10):
        print(' '+str(i)+": "+ctime())
        ips=[]
        file_handler=open('ips','a+')
        for i in range(10000000):
            ips.append(str(random.randint(0,255))+'.'+str(random.randint(0,255))+'.'+str(random.randint(0,255))+'.'+str(random.randint(0,255))+'\n')
        file_handler.writelines(ips)
        file_handler.close()

def hash_split():
    counter=0
    ips=[]
    for i in range(10):
        ips.append([])

    with open('ips','r') as file_handler:
        for line in file_handler:
            if counter==1000000:
                for i in range(10):
                    file_writer=open("ips_"+str(i),'a+')
                    file_writer.writelines(ips[i])
                    file_writer.close()
                    ips[i][:]=[]
                counter=0   
            counter=counter+1    
            line_list=line.split('.')
            index=(int(line_list[0]))%10
            ips[index].append(line)

def find_top():
    res=""
    res_number=0
    for i in range(10):
        result={}
        tmp_res=""
        tmp_res_number=0
        with open("ips_"+str(i),'r') as file_handler:
            for line in file_handler:
                if line in result:
                    result[line]=result[line]+1
                else:
                    result[line]=1
        for k,v in result.items():
            if v>tmp_res_number:
                tmp_res_number=v
                tmp_res=k
        print(tmp_res+' '+str(tmp_res_number)+' in file ips_'+str(i))
        if tmp_res_number>res_number:
            res_number=tmp_res_number
            res=tmp_res
    print(res+' '+str(res_number))

if __name__=='__main__':
    print('hello')
    generate_ip()
    hash_split()
    find_top()
