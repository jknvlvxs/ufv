import ApartmentTwoToneIcon from '@mui/icons-material/ApartmentTwoTone';
import DescriptionTwoToneIcon from '@mui/icons-material/DescriptionTwoTone';
import DesignServicesTwoToneIcon from '@mui/icons-material/DesignServicesTwoTone';
import LocationCityIcon from '@mui/icons-material/LocationCityTwoTone';
import PersonTwoToneIcon from '@mui/icons-material/PersonTwoTone';
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
        link: '/dashboards/home',
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
        link: '/apartments',
      },
      {
        name: 'Clientes',
        icon: PersonTwoToneIcon,
        link: '/clients',
      },
      {
        name: 'Reservas',
        icon: PersonTwoToneIcon,
        link: '/clients',
      },
      {
        name: 'Hospedagem',
        icon: PersonTwoToneIcon,
        link: '/clients',
      },
      {
        name: 'Contratos',
        icon: DescriptionTwoToneIcon,
        link: '/contracts',
      },
    ],
  },
];

export default menuItems;
