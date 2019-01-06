APP = qttest

# Add any other object files to this list below
APP_OBJS = qttest.o

all: build

build: $(APP)

$(APP): $(APP_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(APP_OBJS) $(LDLIBS)
