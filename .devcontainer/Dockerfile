FROM dainack/ros2:latest

#ENV DEBIAN_FRONTEND=noninteractive
#RUN apt-get update && apt-get install -y \
#    make \
#    build-essential \
#    libssl-dev \
#    zlib1g-dev \
#    libbz2-dev \
#    libreadline-dev \
#    libsqlite3-dev \
#    wget \
#    curl \
#    llvm \
#    libncurses5-dev \
#    libncursesw5-dev \
#    xz-utils \
#    tk-dev \
#    libffi-dev \
#    liblzma-dev \
#    python-openssl \
#    git

#ARG python_version=3.8.2

#ENV HOME /root
#ENV PATH $HOME/.pyenv/bin:$PATH
#RUN git clone https://github.com/pyenv/pyenv.git $HOME/.pyenv && \
#    echo 'eval "$(pyenv init -)"' >> ~/.bashrc && \
#    eval "$(pyenv init -)" && \
#    pyenv install -v ${python_version} && \
#    pyenv global ${python_version} && \
#    pip install cmake-format

RUN apt-get update && apt-get install -y curl

RUN curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py \
    && python3 get-pip.py \
    && pip3 install -U pip \
    && pip3 install cmake-format

# Clean up
RUN apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*
