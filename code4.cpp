struct Specialization {
    explicit Specialization(const string& val) {
        value = val;
    }

    string value;
};

struct Course {
    explicit Course(const string& cour) {
        value = cour;
    }

    string value;

};

struct Week {
    explicit Week(const string& wek) {
        value = wek;
    }

    string value;
};

struct LectureTitle {
  LectureTitle(const Specialization& spec, 
  const Course& cour, 
  const Week& wek) {
      specialization = spec.value;
      course = cour.value;
      week = wek.value;
  }

  string specialization;
  string course;
  string week;
};


