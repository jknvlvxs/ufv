import { DateTimeValidationError } from '@mui/lab/internal/pickers/hooks/useValidation';

export type ClientStatus = 'active' | 'inactive';

export interface Client {
  id: string;
  name: string;
  status: ClientStatus;

  documentFile: any;
  receiptAddress: any;
  receiptIncome: any;

  goal: string;
  propertyCode: string;
  propertyAddress: string;
  district: string;
  ownerName: string;
  rentValue: string;
  deadline: string;
  readjustment: string;
  startDate: Date;
  finishDate: Date;
  comments: string;

  phoneNumber: string;
  email: string;
  originAddress: string;
  guardianPhoneNumber: string;
  guardianContactInformation: string;
  reasonOfTravel: string;

  physical: string;
  juridical: string;

  personValue: string;
  guarantorValue: string;

  guarantorName: string;
  guarantorAddress: string;
  guarantorResidentialTime: string;
  guarantorDistrict: string;
  guarantorCep: string;
  guarantorCity: string;
  guarantorResidentialPhone: string;
  guarantorEmail: string;
  guarantorCellPhone: string;
  guarantorNationality: string;
  guarantorNaturalFrom: string;
  guarantorDateOfBirth: Date;
  guarantorCivilStatus: string;
  guarantorRg: string;
  guarantorCpf: string;
  guarantorProfession: string;
  guarantorFatherName: string;
  guarantorMotherName: string;

  guarantorSpouseName: string;
  guarantorSpouseNationality: string;
  guarantorSpouseProfession: string;
  guarantorSpouseRg: string;
  guarantorSpouseCpf: string;
  guarantorSpouseNumberOfSons: string;

  guarantorName_2: string;
  guarantorAddress_2: string;
  guarantorResidentialTime_2: string;
  guarantorDistrict_2: string;
  guarantorCep_2: string;
  guarantorCity_2: string;
  guarantorResidentialPhone_2: string;
  guarantorEmail_2: string;
  guarantorCellPhone_2: string;
  guarantorNationality_2: string;
  guarantorNaturalFrom_2: string;
  guarantorDateOfBirth_2: Date;
  guarantorCivilStatus_2: string;
  guarantorRg_2: string;
  guarantorCpf_2: string;
  guarantorProfession_2: string;
  guarantorFatherName_2: string;
  guarantorMotherName_2: string;

  guarantorSpouseName_2: string;
  guarantorSpouseNationality_2: string;
  guarantorSpouseProfession_2: string;
  guarantorSpouseRg_2: string;
  guarantorSpouseCpf_2: string;
  guarantorSpouseNumberOfSons_2: string;

  // Physical Person
  name_physicalPerson_locatario: string;
  fatherName_physicalPerson_locatario: string;
  motherName_physicalPerson_locatario: string;
  address_physicalPerson_locatario: string;
  residenceTime_physicalPerson_locatario: string;
  district_physicalPerson_locatario: string;
  cep_physicalPerson_locatario: string;
  city_physicalPerson_locatario: string;
  homePhone_physicalPerson_locatario: string;
  email_physicalPerson_locatario: string;
  phoneNumber_physicalPerson_locatario: string;
  nationality_physicalPerson_locatario: string;
  naturalFrom_physicalPerson_locatario: string;
  dateOfBirth_physicalPerson_locatario: Date;
  civilStatus_physicalPerson_locatario: string;
  cpf_physicalPerson_locatario: string;
  rg_physicalPerson_locatario: string;
  profession_physicalPerson_locatario: string;
  nameOfPayRent_physicalPerson_locatario: string;
  rentValue_physicalPerson_locatario: string;
  addressOfPayRent_physicalPerson_locatario: string;
  phoneNumberOfPayRent_physicalPerson_locatario: string;

  company_physicalPerson: string;
  admissionDateCompany_physicalPerson: Date;
  addressOfCompany_physicalPerson: string;
  phoneNumberOfCompany_physicalPerson: string;
  districtOfCompany_physicalPerson: string;
  cityOfCompany_physicalPerson: string;
  positionInCompany_physicalPerson: string;
  salary_physicalPerson: string;
  others_physicalPerson: string;

  spouseName_physicalPerson: string;
  spouseNationality_physicalPerson: string;
  spouseProfession_physicalPerson: string;
  spouseRg_physicalPerson: string;
  spouseCpf_physicalPerson: string;
  spouseNumberOfSons_physicalPerson: string;

  // References
  othersIncome: string;

  referenceBankName: string;
  referenceBankAgency: string;
  referenceBankAccount: string;
  referenceBankCity: string;
  referenceBankYearOpenAccount: Date;

  referenceBankName_2: string;
  referenceBankAgency_2: string;
  referenceBankAccount_2: string;
  referenceBankCity_2: string;
  referenceBankYearOpenAccount_2: Date;

  referenceCommercialName: string;
  referenceCommercialAddress: string;
  referenceCommercialPhone: string;

  referenceCommercialName_2: string;
  referenceCommercialAddress_2: string;
  referenceCommercialPhone_2: string;

  referencePersonalName: string;
  referencePersonalAddress: string;
  referencePersonalPhone: string;

  referencePersonalName_2: string;
  referencePersonalAddress_2: string;
  referencePersonalPhone_2: string;

  // Juridical Person
  companyName_juridicalPerson_locatario: string;
  companyRepresentative_juridicalPerson_locatario: string;
  profession_juridicalPerson_locatario: string;
  address_juridicalPerson_locatario: string;
  residenceTime_juridicalPerson_locatario: string;
  district_juridicalPerson_locatario: string;
  cep_juridicalPerson_locatario: string;
  city_juridicalPerson_locatario: string;
  civilStatus_juridicalPerson_locatario: string;
  cpf_juridicalPerson_locatario: string;
  rg_juridicalPerson_locatario: string;
  dateOfBirth_juridicalPerson_locatario: Date;
  phoneNumber_juridicalPerson_locatario: string;
  cnpj_juridicalPerson_locatario: string;
  stateRegistration_juridicalPerson_locatario: string;
  phoneNumberCommercial_juridicalPerson_locatario: string;
  branchOfActivityCompany_juridicalPerson_locatario: string;
  timeOfActivityCompany_juridicalPerson_locatario: string;
  previousAddress_juridicalPerson_locatario: string;
  phoneResidential_juridicalPerson_locatario: string;
  companyDistrict_juridicalPerson_locatario: string;
  companyCep_juridicalPerson_locatario: string;
  companyCity_juridicalPerson_locatario: string;
}
