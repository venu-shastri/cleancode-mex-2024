class Icon:
    def __init__(self, subtype):
        self.speed = 0.0
        self.glow = 0.0
        self.energy = 0.0
        self.x = 0
        self.y = 0
        self.subtype = subtype  # spinner, slider, or hopper

        # Fields associated with specific subtypes
        self.clockwise = False      # needed for spinner
        self.expand = False         # needed for spinner
        self.vertical = False       # needed for slider
        self.distance = 0           # needed for slider
        self.visible = False        # needed for hopper
        self.xcoord = 0             # needed for hopper
        self.ycoord = 0             # needed for hopper

        # Initialize fields based on subtype
        if self.subtype == 1:
            self.clockwise = True
            self.expand = False
        elif self.subtype == 2:
            self.vertical = True
            self.distance = 0
        elif self.subtype == 3:
            self.visible = True
            self.xcoord = 0
            self.ycoord = 0

    def spin(self):
        print("Spinning...")

    def slide(self):
        print("Sliding...")

    def hop(self):
        print("Hopping...")

    def move(self):
        if self.subtype == 1:
            self.spin()
        elif self.subtype == 2:
            self.slide()
        else:
            self.hop()

    def flair(self):
        if self.subtype == 1:
            self.spin()
        elif self.subtype == 2:
            self.slide()
        else:
            self.hop()

# Example of using the Icon class
my_icon = Icon(1)  # Instantiate with subtype 1 (spinner)
my_icon.move()
my_icon.flair()
