import random
colors=['red','green','blue','yellow','pink','red2','gold2','gray','brown']
def introcolor():
    fg= random.choice(colors)
    sliderLaber.config(fg=fg)
    sliderLaber.after(20,introcolor)
def IntroLabelTick():
    global count,text
    if(count>=len(aa)):
        count =-1
        text=''
        sliderLaber.config(text=text)
    else:
        text = text + aa[count]
        sliderLaber.config(text=text)
        count +=1
    sliderLaber.after(100,IntroLabelTick)