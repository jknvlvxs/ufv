import * as yup from 'yup';
export default class Validation {
  static schema = yup.object().shape({
    personValue: yup.string().required().default('physical'),
    guarantorValue: yup.string().required().default('no'),

    //   ///////////////////////// CreateClientForm /////////////////////////
    goal: yup.string().required('Campo obrigatório!'),
    propertyCode: yup.string().required('Campo obrigatório!'),
    propertyAddress: yup.string().required('Campo obrigatório!'),
    district: yup.string().required('Campo obrigatório!'),
    ownerName: yup.string().required('Campo obrigatório!'),
    rentValue: yup.string().required('Campo obrigatório!'),
    deadline: yup.string().required('Campo obrigatório!'),
    readjustment: yup.string().required('Campo obrigatório!'),
    startDate: yup.date().nullable().required('Campo obrigatório!'),
    finishDate: yup.date().nullable().required('Campo obrigatório!'),
    comments: yup.string(),

    documentFile: yup.mixed().required('Anexe o arquivo solicitado!'),
    receiptAddress: yup.mixed().required('Anexe o arquivo solicitado!'),
    receiptIncome: yup.mixed().required('Anexe o arquivo solicitado!'),

    //  ///////////////////////// Physical Person  /////////////////////////
    name_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    fatherName_physicalPerson_locatario: yup
      .string()
      .when('personValue', { is: 'physical', then: yup.string() }),
    motherName_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    address_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    residenceTime_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    district_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    cep_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup
        .string()
        .min(8, 'Este campo deve ter 8 dígitos!')
        .required('Campo obrigatório!'),
    }),
    city_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    homePhone_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup
        .string()
        .min(10, 'Telefone inválido!')
        .max(11, 'Telefone inválido!')
        .required('Campo obrigatório!'),
    }),
    email_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup
        .string()
        .email('Email inválido!')
        .required('Campo obrigatório!'),
    }),
    phoneNumber_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup
        .string()
        .min(10, 'Telefone inválido!')
        .max(11, 'Telefone inválido!')
        .required('Campo obrigatório!'),
    }),
    nationality_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    naturalFrom_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    dateOfBirth_physicalPerson_locatario: yup.date().when('personValue', {
      is: 'physical',
      then: yup.date().required('Campo obrigatório!'),
    }),
    civilStatus_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    rg_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    cpf_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup
        .string()
        .min(11, 'Este campo deve ter 11 dígitos!')
        .required('Campo obrigatório!'),
    }),
    profession_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),

    liveOwnHouse_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),

    payRent_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),

    nameOfPayRent_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().when('payRent_physicalPerson_locatario', {
        is: 'yes',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
    rentValue_physicalPerson_locatario: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().when('payRent_physicalPerson_locatario', {
        is: 'yes',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
    addressOfPayRent_physicalPerson_locatario: yup
      .string()
      .when('personValue', {
        is: 'physical',
        then: yup.string().when('payRent_physicalPerson_locatario', {
          is: 'yes',
          then: yup.string().required('Campo obrigatório!'),
        }),
      }),
    phoneNumberOfPayRent_physicalPerson_locatario: yup
      .string()
      .when('personValue', {
        is: 'physical',
        then: yup.string().when('payRent_physicalPerson_locatario', {
          is: 'yes',
          then: yup
            .string()
            .min(10, 'Telefone inválido!')
            .max(11, 'Telefone inválido!')
            .required('Campo obrigatório!'),
        }),
      }),
    company_physicalPerson: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    admissionDateCompany_physicalPerson: yup
      .date()
      .nullable()
      .when('personValue', {
        is: 'physical',
        then: yup.date().nullable().required('Campo obrigatório!'),
      }),
    addressOfCompany_physicalPerson: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    phoneNumberOfCompany_physicalPerson: yup.string().when('personValue', {
      is: 'physical',
      then: yup
        .string()
        .min(10, 'Telefone inválido!')
        .max(11, 'Telefone inválido!')
        .required('Campo obrigatório!'),
    }),
    districtOfCompany_physicalPerson: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    cityOfCompany_physicalPerson: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    positionInCompany_physicalPerson: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    salary_physicalPerson: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().required('Campo obrigatório!'),
    }),

    others_physicalPerson: yup
      .string()
      .when('personValue', { is: 'physical', then: yup.string() }),

    spouseName_physicalPerson: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().when('civilStatus_physicalPerson_locatario', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
    spouseNationality_physicalPerson: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().when('civilStatus_physicalPerson_locatario', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
    spouseProfession_physicalPerson: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().when('civilStatus_physicalPerson_locatario', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
    spouseRg_physicalPerson: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().when('civilStatus_physicalPerson_locatario', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
    spouseCpf_physicalPerson: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().when('civilStatus_physicalPerson_locatario', {
        is: 'casado(a)',
        then: yup
          .string()
          .min(11, 'Este campo deve ter 11 dígitos!')
          .required('Campo obrigatório!'),
      }),
    }),
    spouseNumberOfSons_physicalPerson: yup.string().when('personValue', {
      is: 'physical',
      then: yup.string().when('civilStatus_physicalPerson_locatario', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),

    othersIncome: yup.string(),

    referenceBankName: yup.string(),
    referenceBankAgency: yup.string(),
    referenceBankAccount: yup.string(),
    referenceBankCity: yup.string(),

    referenceBankYearOpenAccount: yup.date().nullable(),

    referenceBankName_2: yup.string(),
    referenceBankAgency_2: yup.string(),
    referenceBankAccount_2: yup.string(),
    referenceBankCity_2: yup.string(),
    referenceBankYearOpenAccount_2: yup.date().nullable(),

    referenceCommercialName: yup.string().required('Campo obrigatório!'),
    referenceCommercialAddress: yup.string().required('Campo obrigatório!'),
    referenceCommercialPhone: yup
      .string()
      .min(10, 'Telefone inválido!')
      .max(11, 'Telefone inválido!')
      .required('Campo obrigatório!'),
    referenceCommercialName_2: yup.string().required('Campo obrigatório!'),
    referenceCommercialAddress_2: yup.string().required('Campo obrigatório!'),
    referenceCommercialPhone_2: yup
      .string()
      .min(10, 'Telefone inválido!')
      .max(11, 'Telefone inválido!')
      .required('Campo obrigatório!'),
    referencePersonalName: yup.string().required('Campo obrigatório!'),
    referencePersonalAddress: yup.string().required('Campo obrigatório!'),
    referencePersonalPhone: yup
      .string()
      .min(10, 'Telefone inválido!')
      .max(11, 'Telefone inválido!')
      .required('Campo obrigatório!'),
    referencePersonalName_2: yup.string().required('Campo obrigatório!'),
    referencePersonalAddress_2: yup.string().required('Campo obrigatório!'),
    referencePersonalPhone_2: yup
      .string()
      .min(10, 'Telefone inválido!')
      .max(11, 'Telefone inválido!')
      .required('Campo obrigatório!'),

    // /////////////////////// Juridical Person /////////////////////////
    companyName_juridicalPerson_locatario: yup.string().when('personValue', {
      is: 'juridical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    companyRepresentative_juridicalPerson_locatario: yup
      .string()
      .when('personValue', {
        is: 'juridical',
        then: yup.string().required('Campo obrigatório!'),
      }),
    profession_juridicalPerson_locatario: yup.string().when('personValue', {
      is: 'juridical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    address_juridicalPerson_locatario: yup.string().when('personValue', {
      is: 'juridical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    residenceTime_juridicalPerson_locatario: yup.string().when('personValue', {
      is: 'juridical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    district_juridicalPerson_locatario: yup.string().when('personValue', {
      is: 'juridical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    cep_juridicalPerson_locatario: yup.string().when('personValue', {
      is: 'juridical',
      then: yup
        .string()
        .min(8, 'Este campo deve ter 8 dígitos!')
        .required('Campo obrigatório!'),
    }),
    city_juridicalPerson_locatario: yup.string().when('personValue', {
      is: 'juridical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    civilStatus_juridicalPerson_locatario: yup.string().when('personValue', {
      is: 'juridical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    cpf_juridicalPerson_locatario: yup.string().when('personValue', {
      is: 'juridical',
      then: yup
        .string()
        .min(11, 'Este campo deve ter 11 dígitos!')
        .required('Campo obrigatório!'),
    }),
    rg_juridicalPerson_locatario: yup.string().when('personValue', {
      is: 'juridical',
      then: yup.string().required('Campo obrigatório!'),
    }),
    dateOfBirth_juridicalPerson_locatario: yup
      .date()
      .nullable()
      .when('personValue', {
        is: 'juridical',
        then: yup.date().nullable().required('Campo obrigatório!'),
      }),
    phoneNumber_juridicalPerson_locatario: yup.string().when('personValue', {
      is: 'juridical',
      then: yup
        .string()
        .min(10, 'Telefone inválido!')
        .max(11, 'Telefone inválido!')
        .required('Campo obrigatório!'),
    }),
    cnpj_juridicalPerson_locatario: yup.string().when('personValue', {
      is: 'juridical',
      then: yup
        .string()
        .min(14, 'Este campo deve ter 14 dígitos!')
        .required('Campo obrigatório!'),
    }),
    stateRegistration_juridicalPerson_locatario: yup
      .string()
      .when('personValue', {
        is: 'juridical',
        then: yup.string().required('Campo obrigatório!'),
      }),
    phoneNumberCommercial_juridicalPerson_locatario: yup
      .string()
      .when('personValue', {
        is: 'juridical',
        then: yup
          .string()
          .min(10, 'Telefone inválido!')
          .max(11, 'Telefone inválido!')
          .required('Campo obrigatório!'),
      }),
    branchOfActivityCompany_juridicalPerson_locatario: yup
      .string()
      .when('personValue', {
        is: 'juridical',
        then: yup.string().required('Campo obrigatório!'),
      }),
    timeOfActivityCompany_juridicalPerson_locatario: yup
      .string()
      .when('personValue', {
        is: 'juridical',
        then: yup.string().required('Campo obrigatório!'),
      }),
    previousAddress_juridicalPerson_locatario: yup
      .string()
      .when('personValue', {
        is: 'juridical',
        then: yup.string().required('Campo obrigatório!'),
      }),
    phoneResidential_juridicalPerson_locatario: yup
      .string()
      .when('personValue', {
        is: 'juridical',
        then: yup
          .string()
          .min(10, 'Telefone inválido!')
          .max(11, 'Telefone inválido!')
          .required('Campo obrigatório!'),
      }),
    companyDistrict_juridicalPerson_locatario: yup
      .string()
      .when('personValue', {
        is: 'juridical',
        then: yup.string().required('Campo obrigatório!'),
      }),
    companyCep_juridicalPerson_locatario: yup.string().when('personValue', {
      is: 'juridical',
      then: yup
        .string()
        .min(8, 'Este campo deve ter 8 dígitos!')
        .required('Campo obrigatório!'),
    }),
    companyCity_juridicalPerson_locatario: yup.string().when('personValue', {
      is: 'juridical',
      then: yup.string().required('Campo obrigatório!'),
    }),

    //   ///////////////////////// Guarantor  /////////////////////////
    guarantorName: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorAddress: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorResidentialTime: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorDistrict: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorCep: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup
        .string()
        .min(8, 'Este campo deve ter 8 dígitos!')
        .required('Campo obrigatório!'),
    }),
    guarantorCity: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorResidentialPhone: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup
        .string()
        .min(10, 'Telefone inválido!')
        .max(11, 'Telefone inválido!')
        .required('Campo obrigatório!'),
    }),
    guarantorEmail: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup
        .string()
        .email('Email inválido!')
        .required('Campo obrigatório!'),
    }),
    guarantorCellPhone: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup
        .string()
        .min(10, 'Telefone inválido!')
        .max(11, 'Telefone inválido!')
        .required('Campo obrigatório!'),
    }),
    guarantorNationality: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorNaturalFrom: yup
      .string()
      .when('guarantorValue', { is: 'yes', then: yup.string().required() }),
    guarantorDateOfBirth: yup.date().nullable().when('guarantorValue', {
      is: 'yes',
      then: yup.date().nullable().required(),
    }),
    guarantorCivilStatus: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorCpf: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup
        .string()
        .min(11, 'Este campo deve ter 11 dígitos!')
        .required('Campo obrigatório!'),
    }),
    guarantorRg: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorProfession: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorFatherName: yup
      .string()
      .when('guarantorValue', { is: 'yes', then: yup.string() }),
    guarantorMotherName: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),

    guarantorSpouseName: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().when('guarantorCivilStatus', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
    guarantorSpouseNationality: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().when('guarantorCivilStatus', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
    guarantorSpouseProfession: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().when('guarantorCivilStatus', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
    guarantorSpouseRg: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().when('guarantorCivilStatus', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
    guarantorSpouseCpf: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().when('guarantorCivilStatus', {
        is: 'casado(a)',
        then: yup
          .string()
          .min(11, 'Este campo deve ter 11 dígitos!')
          .required('Campo obrigatório!'),
      }),
    }),
    guarantorSpouseNumberOfSons: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().when('guarantorCivilStatus', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),

    // ///////////////////////// Guarantor 2 //////////////////////////
    guarantorName_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorAddress_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorResidentialTime_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorDistrict_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorCep_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup
        .string()
        .min(8, 'Este campo deve ter 8 dígitos!')
        .required('Campo obrigatório!'),
    }),
    guarantorCity_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorResidentialPhone_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup
        .string()
        .min(10, 'Telefone inválido!')
        .max(11, 'Telefone inválido!')
        .required('Campo obrigatório!'),
    }),
    guarantorEmail_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup
        .string()
        .email('Email inválido!')
        .required('Campo obrigatório!'),
    }),
    guarantorCellPhone_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup
        .string()
        .min(10, 'Telefone inválido!')
        .max(11, 'Telefone inválido!')
        .required('Campo obrigatório!'),
    }),
    guarantorNationality_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorNaturalFrom_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorDateOfBirth_2: yup
      .date()
      .nullable()
      .when('guarantorValue', {
        is: 'yes',
        then: yup.date().nullable().required('Campo obrigatório!'),
      }),
    guarantorCivilStatus_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorCpf_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup
        .string()
        .min(11, 'Este campo deve ter 11 dígitos!')
        .required('Campo obrigatório!'),
    }),
    guarantorRg_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorProfession_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),
    guarantorFatherName_2: yup
      .string()
      .when('guarantorValue', { is: 'yes', then: yup.string() }),
    guarantorMotherName_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().required('Campo obrigatório!'),
    }),

    guarantorSpouseName_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().when('guarantorCivilStatus_2', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
    guarantorSpouseNationality_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().when('guarantorCivilStatus_2', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
    guarantorSpouseProfession_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().when('guarantorCivilStatus_2', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
    guarantorSpouseRg_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().when('guarantorCivilStatus_2', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
    guarantorSpouseCpf_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().when('guarantorCivilStatus_2', {
        is: 'casado(a)',
        then: yup
          .string()
          .min(11, 'Este campo deve ter 11 dígitos!')
          .required('Campo obrigatório!'),
      }),
    }),
    guarantorSpouseNumberOfSons_2: yup.string().when('guarantorValue', {
      is: 'yes',
      then: yup.string().when('guarantorCivilStatus_2', {
        is: 'casado(a)',
        then: yup.string().required('Campo obrigatório!'),
      }),
    }),
  });
}
