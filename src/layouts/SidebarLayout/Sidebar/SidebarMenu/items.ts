import ApartmentTwoToneIcon from '@mui/icons-material/ApartmentTwoTone';
import DescriptionTwoToneIcon from '@mui/icons-material/DescriptionTwoTone';
import DesignServicesTwoToneIcon from '@mui/icons-material/DesignServicesTwoTone';
import LocationCityIcon from '@mui/icons-material/LocationCityTwoTone';
import PersonTwoToneIcon from '@mui/icons-material/PersonTwoTone';
import BedTwoToneIcon from '@mui/icons-material/BedTwoTone';
import HotelTwoToneIcon from '@mui/icons-material/HotelTwoTone';
import FastfoodTwoToneIcon from '@mui/icons-material/FastfoodTwoTone';

import { ReactNode } from 'react';

export interface MenuItem {
  link?: string;
  icon?: ReactNode;
  badge?: string;
  items?: MenuItem[];
  name: string;
}

export interface MenuItems {
  items: MenuItem[];
  heading: string;
}

const menuItems: MenuItems[] = [
  {
    heading: '',
    items: [
      {
        name: 'Início',
        link: '/home',
        icon: DesignServicesTwoToneIcon,
      },
    ],
  },
  {
    heading: 'Gerenciamento',
    items: [
      {
        name: 'Hotéis',
        icon: LocationCityIcon,
        link: '/hotels',
      },
      {
        name: 'Tipos de Apartamentos',
        icon: ApartmentTwoToneIcon,
        link: '/apartments/type',
      },
      {
        name: 'Clientes',
        icon: PersonTwoToneIcon,
        link: '/clients',
      },
      {
        name: 'Reservas',
        icon: BedTwoToneIcon,
        link: '/reservations',
      },
      {
        name: 'Hospedagem',
        icon: HotelTwoToneIcon,
        link: '/accommodation',
      },
      {
        name: 'Consumos',
        icon: FastfoodTwoToneIcon,
        link: '/expenditure',
      },
    ],
  },
];

export default menuItems;
