FROM ubuntu

WORKDIR /home

#-y de auto chon yes
RUN apt-get update && \
    apt-get install -y python3 && \  
    apt-get clean

COPY testclean.py ./testclean.py

CMD ["python3","testclean.py"]