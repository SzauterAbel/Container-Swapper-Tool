IMAGE_NAME := container-swapper
USER_ID := $(shell id -u)
GROUP_ID := $(shell id -g)

build:
	docker build -t $(IMAGE_NAME) .

run:
	docker run -u $(USER_ID):$(GROUP_ID) \
	-v $(CURDIR)/../src:/home/container_swapper/src \
	-v $(CURDIR)/../tools:/home/container_swapper/tools \
	-v $(CURDIR)/../build:/home/container_swapper/build \
	--rm --interactive --tty $(IMAGE_NAME) /bin/bash

clean:
	docker image rm $(IMAGE_NAME)